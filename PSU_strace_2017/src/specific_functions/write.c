/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        write.c
*/

#include "strace.h"

void print_space(char **syscall)
{
	for (int i = strlen(*syscall); i < 39; i++)
		strcat(*syscall, " ");
}

void write_func(flags_t *flags, struct user_regs_struct *data)
{
	char *syscall = malloc(sizeof(char) * 256);

	(void) flags;
	if (!syscall)
		exit(84);
	sprintf(syscall, "%s(", SYSCALL_NAMES[data->orig_rax].name);
	sprintf(syscall, "%s%d, %s, %d", syscall, (int) data->rdi,
	print_string(data->rsi), (int) data->rdx);
	sprintf(syscall, "%s%s)", syscall, get_string_at(data->rsi));
	print_space(&syscall);
	printf("%s = %d\n", syscall, (int) data->rax);
}
