/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(std::string const &name)
	: Toy(WOODY, name, "woody.txt")
{
}

Woody::Woody(std::string const &name, std::string const &filename)
	: Toy(WOODY, name, filename)
{
}

Woody::~Woody()
{
}

void	Woody::speak(std::string string)
{
	std::cout << "WOODY: " << getName() << " \"" << string << "\"\n";
}
