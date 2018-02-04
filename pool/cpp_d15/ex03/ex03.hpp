/*
** EPITECH PROJECT, 2018
** cpp_d15
** File description:
**        ex03.hpp
*/

#ifndef _EX03_
# define _EX03_

#include <string>
#include <iostream>

template<typename T>
void foreach(const T * tab, void (func)(const T &), int size)
{
	int i = 0;

	while (i < size)
	{
		(*func)(tab[i]);
		i++;
	}
}

template<typename T>
void print(const T & a)
{
	std::cout << a << std::endl;
}

#endif
