/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        print_detailed.c
*/

#include "strace.h"

const types_rel_t g_types_rel[] =
{
	{1, &print_unsigned},
	{2, &print_int},
	{3, &print_string},
	{4, &print_char},
	{5, &print_int}
};

/*
** Use of arithmetic pointer to get the type stocked in param_typeX
*/

static char *put_param(struct user_regs_struct *data, int i, system_call_t sysc)
{
	char *str = malloc(sizeof(char) * 256);
	unsigned int j = 0;
	params_t *params = get_params(data);
	int addr;
	int param_type = 0;
	int temp;

	for (j = 0; j < 6; j++) {
		if ((int) j == i)
			break;
	}
	param_type = *((int *)&(sysc.param_type1) + j);
	for (temp = 0; temp < 5; temp++) {
		if (g_types_rel[temp].value == param_type)
			break;
	}
	addr = params[j].val;
	str = g_types_rel[temp].print_related(addr);
	return (str);
}

/*
** Prints a syscall with custom-formatted parameters
** @i is the current param (1 to 6)
** @i is passed as argument to link the param to register (from param_t[])
** @sysc is passed to pick the type of the variable (address in struct)
*/

void print_detailed(struct user_regs_struct *data)
{
	char format[256];

	sprintf(format, "%s(", SYSCALL_NAMES[data->orig_rax].name);
	for (int i = 0; i < SYSCALL_NAMES[data->orig_rax].nparams; i++) {
		strcat(format, put_param(data, i,
		SYSCALL_NAMES[data->orig_rax]));
		if (i + 1 < SYSCALL_NAMES[data->orig_rax].nparams)
			strcat(format, ", ");
	}
	strcat(format, ")");
	for (int i = strlen(format); i < 39; i++)
		strcat(format, " ");
	if ((unsigned int) data->rax != 0)
		printf("%s = %d\n", format, (unsigned int) data->rax);
	else
		printf("%s = 0\n", format);
}
