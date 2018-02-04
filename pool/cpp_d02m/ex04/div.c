/*
** EPITECH PROJECT, 2018
** ex04
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex04
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a / b);
}

float decimale_div(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a / (float)b);
}

void	exec_div (div_t *operation)
{
	float	res_f = 0.0;
	int	res = 0;
	int	a = 0;
	int	b = 0;

	if (operation->div_type == INTEGER) {
		a = ((integer_op_t *) operation->div_op)->a;
		b = ((integer_op_t *) operation->div_op)->b;
		res = integer_div(a, b);
		((integer_op_t *) operation->div_op)->res = res;
	}
	else if (operation->div_type == DECIMALE) {
		a = ((decimale_op_t *) operation->div_op)->a;
		b = ((decimale_op_t *) operation->div_op)->b;
		res_f = integer_div(a, b);
		((decimale_op_t *) operation->div_op)->res = res_f;
	}
	else
	return;
}
