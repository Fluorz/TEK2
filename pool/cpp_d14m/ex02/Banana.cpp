/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Banana.cpp
*/

#include "Banana.hpp"

Banana::Banana()
	: Fruit("banana", 5)
{

}

Banana::~Banana()
{
}

std::string Banana::getName() const
{
	return (_name);
}

int	Banana::getVitamins() const
{
	return (_vitamins);
}
