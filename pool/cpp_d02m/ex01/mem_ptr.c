/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        mem_ptr.c
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
	*res = malloc(sizeof(char) * strlen(str1) + strlen(str2) + 1);
	if (res == NULL)
	return;
	*res = strcpy(*res, str1);
	*res = strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
	str_op->res = malloc(sizeof(char) * strlen(str_op->str1)
	 + strlen(str_op->str2) + 1);
	 if (str_op->res == NULL)
	 return;
	 str_op->res = strcpy(str_op->res, str_op->str1);
	 str_op->res = strcat(str_op->res, str_op->str2);
}
