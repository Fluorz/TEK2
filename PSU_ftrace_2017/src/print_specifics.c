/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        print_specifics.c
*/

#include "strace.h"

const functions_t g_funcs[] =
{
	{"access", &access_func},
	{"open", &open_func},
	{"write", &write_func}
};

int print_specifics(flags_t *flags, struct user_regs_struct *data)
{
	size_t i = 0;

	for (i = 0; i < sizeof(g_funcs) / sizeof(g_funcs[0]); i++) {
		if (strcmp(SYSCALL_NAMES[data->orig_rax].name,
			g_funcs[i].name) == 0) {
			g_funcs[i].spec_func(flags, data);
			return (1);
		}
	}
	return (0);
}
