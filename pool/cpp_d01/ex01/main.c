/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        main.c
*/

#include <ctype.h>

int my_getnbr(char *str)
{
	int num = 0;
	int i = 0;

	while (isdigit(str[i]))	{
		num = num * 10 + str[i] - 48;
		i = i + 1;
	}
	return (num);
}
