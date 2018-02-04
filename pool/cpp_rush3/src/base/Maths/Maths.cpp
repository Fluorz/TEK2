/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Maths.cpp
*/

#include "Maths.hpp"

Maths::Maths()
{
}

Maths::~Maths()
{
}

template <typename T>
double Maths::Percent(T &left, T &right)
{
	double res = 0;

	res = ((double) left * (double) 100) / ((double) right);
	return res;
}
