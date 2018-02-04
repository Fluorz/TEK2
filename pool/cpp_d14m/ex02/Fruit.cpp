/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string const &name, int const vitamins)
	: _name(name), _vitamins(vitamins)
{

}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
	return (_name);
}

int	Fruit::getVitamins() const
{
	return (_vitamins);
}
