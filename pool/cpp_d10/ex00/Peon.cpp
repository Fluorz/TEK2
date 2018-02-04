/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Peon.cpp
*/

#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string name)
	: Victim(name)
{
	std::cout << "Zog zog.\n";
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

void	Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony!\n";
}
