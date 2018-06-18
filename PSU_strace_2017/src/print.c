/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        print.c
*/

#include "strace.h"

params_t *get_params(struct user_regs_struct *data)
{
	params_t *params = malloc(sizeof(params_t) * 6);

	params[0].i = 0;
	params[0].val = data->rdi;
	params[1].i = 1;
	params[1].val = data->rsi;
	params[2].i = 2;
	params[2].val = data->rdx;
	params[3].i = 3;
	params[3].val = data->r10;
	params[4].i = 4;
	params[4].val = data->r8;
	params[5].i = 5;
	params[5].val = data->r9;
	return (params);
}

static char *put_param(struct user_regs_struct *data, int i)
{
	char *str = malloc(sizeof(char) * 256);
	unsigned int j = 0;
	params_t *params = get_params(data);

	for (j = 0; j < 6; j++) {
		if ((int) j == i)
			break;
	}
	sprintf(str, "0x%x", params[j].val);
	return (str);
}

/*
** Prints a syscall with hexa-formatted parameters
*/

void print_syscall(struct user_regs_struct *data)
{
	char format[256];

	sprintf(format, "%s(", SYSCALL_NAMES[data->orig_rax].name);
	for (int i = 0; i < SYSCALL_NAMES[data->orig_rax].nparams; i++) {
		strcat(format, put_param(data, i));
		if (i + 1 < SYSCALL_NAMES[data->orig_rax].nparams)
			strcat(format, ", ");
	}
	sprintf(format, "%s%s)", format,
	strcmp(SYSCALL_NAMES[data->orig_rax].name,
	"write") == 0 ? get_string_at(data->rsi) : "");
	for (int i = strlen(format); i < 39; i++) {
		strcat(format, " ");
	}
	if ((unsigned int) data->rax != 0)
		printf("%s = 0x%x\n", format, (unsigned int) data->rax);
	else
		printf("%s = 0\n", format);
}
