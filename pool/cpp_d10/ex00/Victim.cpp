/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Victim.cpp
*/

#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string name)
	: _name(name)
{
	std::cout << "Some random victim called " << _name << " just popped!\n";
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!\n";
}

std::string Victim::getName() const
{
	return (this->_name);
}

void	Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!\n";
}

std::ostream &operator<<(std::ostream &s, const Victim &victim)
{
	return (s << "I'm " << victim.getName() << " and i like otters!\n");
}
