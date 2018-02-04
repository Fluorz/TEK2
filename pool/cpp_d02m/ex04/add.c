/*
** EPITECH PROJECT, 2018
** ex04
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex04
** add.c
*/

#include <stdio.h>
#include "castmania.h"

int normal_add (int a, int b)
{
	return (a + b);
}

int absolute_add(int a, int b)
{
	if (a < 0)
		a = -a;
	else if (b < 0)
		b = -b;
	else
		return (a + b);
	return (a + b);
}

void exec_add(add_t *operation)
{
	int	res = 0;
	int	a = 0;
	int	b = 0;

	if (operation->add_type == NORMAL) {
		a = operation->add_op.a;
		b = operation->add_op.b;
		res = normal_add(a, b);
		operation->add_op.res = res;
	}
	else if (operation->add_type == ABSOLUTE) {
		a = operation->add_op.a;
		b = operation->add_op.b;
		res = absolute_add(a, b);
		operation->add_op.res = res;
		printf("%d\n", operation->add_op.res);
	}
	else
		return;
}
