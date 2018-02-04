/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Sorcerer.cpp
*/

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
	: _name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born!\n";
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title;
	std::cout << ", is dead. Consequences will never be the same!\n";
}

std::string	Sorcerer::getName() const
{
	return (this->_name);
}

std::string	Sorcerer::getTitle() const
{
	return (this->_title);
}

void	Sorcerer::polymorph(const Victim &victim) const
{
	victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &s, const Sorcerer &sorcerer)
{
	return (s << "I am " << sorcerer.getName() << ", "
	<< sorcerer.getTitle() << ", and I like ponies!\n");
}
