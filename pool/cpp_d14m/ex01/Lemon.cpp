/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Lemon.cpp
*/

#include "Lemon.hpp"

Lemon::Lemon()
	: Fruit("lemon", 3)
{
}

Lemon::Lemon(std::string const &name, int const vitamins)
	: Fruit(name, vitamins)
{
}

Lemon::~Lemon()
{
}

std::string Lemon::getName() const
{
	return (_name);
}

int	Lemon::getVitamins() const
{
	return (_vitamins);
}
