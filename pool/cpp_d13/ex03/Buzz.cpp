/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const &name)
	: Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(std::string const &name, std::string const &filename)
	: Toy(BUZZ, name, filename)
{
}

Buzz::~Buzz()
{
}

void	Buzz::speak(std::string string)
{
	std::cout << "BUZZ: " << getName() << " \"" << string << "\"\n";
}
