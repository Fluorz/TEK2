/*
** EPITECH PROJECT, 2018
** cpp_d15
** File description:
**        ex01.hpp
*/

#ifndef _EX01_
# define _EX01_

#include <string>
#include <string.h>

template <typename T>
int compare(const T& a, const T& b)
{
	if (a == b)
		return (0);
	else if (a < b)
		return (-1);
	else
		return (1);
}

template <typename T>
int compare(const char *a, const char *b)
{
	if (strcmp(a, b) == 0)
		return (0);
	if (strcmp(a, b) > 0)
		return (1);
	else
		return (-1);
}

#endif
