/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        access.c
*/

#include "strace.h"

static char *get_flags_at(unsigned int flag)
{
	char *flags = malloc(sizeof(char) * 256);

	if (flag == F_OK)
		strcat(flags, "F_OK");
	else {
		if (flag & R_OK)
			strcat(flags, "R_OK");
		else if (flag & W_OK)
			strcat(flags, "W_OK");
		else
			strcat(flags, "X_OK");
	}
	return (flags);
}

void access_func(flags_t *flags, struct user_regs_struct *data)
{
	char *syscall = malloc(sizeof(char) * 256);

	(void) flags;
	if (!syscall)
		exit(84);
	sprintf(syscall, "%s(\"", SYSCALL_NAMES[data->orig_rax].name);
	strcat(syscall, get_string_at(data->rdi));
	strcat(syscall, "\", ");
	strcat(syscall, get_flags_at(data->rsi));
	strcat(syscall, ")");
	print_space(&syscall);
	if ((int) data->rax < 0) {
		printf("%s = %s\n", syscall,
		"-1 ENOENT (No such file or directory)");
	}
	else {
		printf("%s = %d\n", syscall, (int) data->rax);
	}
}
