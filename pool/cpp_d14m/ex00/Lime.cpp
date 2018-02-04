/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Lime.cpp
*/

#include "Lime.hpp"

Lime::Lime()
	: Lemon("lime", 2)
{
}

Lime::~Lime()
{
}

std::string Lime::getName() const
{
	return (_name);
}

int	Lime::getVitamins() const
{
	return (_vitamins);
}
