/*
** EPITECH PROJECT, 2018
** cpp_d15
** File description:
**        ex04.hpp
*/

#ifndef _EX04_
# define _EX04_

#include <string>

template <typename T>
bool	equal(const T& a, const T& b);

template <typename T>
class Tester
{
public:
	bool equal(const T& a, const T& b);
};

#endif
