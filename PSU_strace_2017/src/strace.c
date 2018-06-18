/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        strace.c
*/

#include "strace.h"

void sig_detach_pid(int sig)
{
	if (sig == SIGINT || sig == SIGKILL || sig == SIGSTOP) {
		ptrace(PTRACE_DETACH, g_pid, NULL, NULL);
		printf("strace: Process %d detached\n", g_pid);
		printf(" <detached ...>\n");
		exit(0);
	}
}

void exit_group(flags_t *flags, struct user_regs_struct *data)
{
	ptrace(PTRACE_DETACH, g_pid, NULL, NULL);
	if (flags->s == true)
		printf("exit_group(%lld) = \?\n", data->rdi);
	else
		printf("exit_group(0x%x) = \?\n", (unsigned int) data->rdi);
	printf("+++ exited with %lld +++\n", data->rdi);
	exit(0);
}

void strace_loop(flags_t *flags, struct user_regs_struct *data, int *status)
{
	ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL);
	waitpid(g_pid, status, 0);
	if (WIFEXITED(*status) || WIFSIGNALED(*status))
		exit_group(flags, data);
	ptrace(PTRACE_GETREGS, g_pid, NULL, data);
	if ((int) data->orig_rax >= 0 && (int) data->orig_rax <= 328) {
		if (flags->s && print_specifics(flags, data) == 0)
			print_detailed(data);
		else
			print_syscall(data);
	}
}

void process_strace(flags_t *flags)
{
	int status = 0;
	struct user_regs_struct data;

	if (flags->p == true)
		signal(SIGINT, sig_detach_pid);
	waitpid(g_pid, &status, 0);
	while (true)
		strace_loop(flags, &data, &status);
}

void controller(flags_t *flags)
{
	if (flags->p == false) {
		g_pid = fork();
		if (g_pid == 0) {
			ptrace(PTRACE_TRACEME, g_pid, 0, 0);
			execvp(flags->av[0], flags->av);
		}
		else {
			ptrace(PTRACE_ATTACH, g_pid, NULL, NULL);
			process_strace(flags);
		}
	}
	else {
		ptrace(PTRACE_ATTACH, g_pid, NULL, NULL);
		printf("strace: Process %d attached\n", g_pid);
		process_strace(flags);
	}
}
