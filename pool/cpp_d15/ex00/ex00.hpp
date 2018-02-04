/*
** EPITECH PROJECT, 2018
** cpp_d15
** File description:
**        ex00.hpp
*/

#ifndef _EX00_
# define _EX00_

#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T c = a;

	a = b;
	b = c;
}

template <typename T>
T min(const T& a, const T& b)
{
	if (a < b)
	return (a);
	else if (a == b)
	return (b);
	else
	return (b);
}

template <typename T>
T max(const T& a, const T& b)
{
	if (a > b)
	return (a);
	else if (a == b)
	return (b);
	else
	return (b);
}

template <typename T>
T add(const T& a, const T& b)
{
	return (a + b);
}

#endif
