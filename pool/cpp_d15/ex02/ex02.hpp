/*
** EPITECH PROJECT, 2018
** cpp_d15
** File description:
**        ex02.hpp
*/

#ifndef _EX02_
# define _EX02_

#include <string>
#include <iostream>

template <typename T>
T min(const T& a, const T& b)
{
	std::cout << "template min\n" ;
	if (a < b)
		return (a);
	else if (a == b)
		return (a);
	else
		return (b);
}

int min(const int a, const int b)
{
	std::cout << "non-template min\n" ;
	if (a < b)
		return (a);
	else if (a == b)
		return (a);
	else
		return (b);
}

template <typename T>
T templateMin(const T array[], size_t size)
{
	T min = array[0];
	for (size_t i = 1; i < size; i++) {
		min = ::min<>(array[i], min);
	}
	return (min);
}

int nonTemplateMin(const int array[], int size)
{
	int min = array[0];
	for (int i = 1; i < size; i++) {
		min = ::min(array[i], min);
	}
	return (min);
}
#endif
