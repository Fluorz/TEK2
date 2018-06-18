/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        open.c
*/

#include "strace.h"

static const open_flags_t g_o_flags[] =
{
	{O_APPEND, "O_APPEND"},
	{O_ASYNC, "O_ASYNC"},
	{O_CLOEXEC, "O_CLOEXEC"},
	{O_CREAT, "O_CREAT"},
	{O_DIRECTORY, "O_DIRECTORY"},
	{O_DSYNC, "O_DSYNC"},
	{O_EXCL, "O_EXCL"},
	{O_NOCTTY, "O_NOCTTY"},
	{O_NOFOLLOW, "O_NOFOLLOW"},
	{O_NONBLOCK, "O_NONBLOCK"},
	{O_SYNC, "O_SYNC"},
	{O_TRUNC, "O_TRUNC"}
};

static char *get_flags_at(unsigned int flag)
{
	char *flags = malloc(sizeof(char) * 256);

	if ((flag & O_RDONLY) == 0)
		strcat(flags, "O_RDONLY");
	else if ((flag & O_WRONLY) == 1)
		strcat(flags, "O_WRONLY");
	else
		strcat(flags, "O_RDWR");
	for (size_t i = 0; i < sizeof(g_o_flags) / sizeof(g_o_flags[0]); i++) {
		if (flag & g_o_flags[i].flag) {
			strcat(flags, "|");
			strcat(flags, g_o_flags[i].to_print);
		}
	}
	return (flags);
}

void open_func(flags_t *flags, struct user_regs_struct *data)
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
	printf("%s = %d\n", syscall, (unsigned int) data->rax);
}
