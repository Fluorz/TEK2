/*
** EPITECH PROJECT, 2018
** cpp_d07m
** File description:
**        Borg.cpp
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
	this->_home = UNICOMPLEX;
	this->_location = this->_home;
	this->_side = 300;
	this->_maxWarp = 9;
	std::cout << "We are the Borgs. Lower your shields and ";
	std::cout << "surrender yourselves unconditionally .";
	std::cout << '\n' ;
	std::cout << "Your biological characteristics and ";
	std::cout << "technologies will be assimilated.";
	std::cout << '\n';
	std::cout << "Resistance is futile." << '\n';
}

Borg::Ship::~Ship()
{
}

void	Borg::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
}

void	Borg::Ship::checkCore()
{
	if (this->_core->checkReactor()->isStable() == true) {
		std::cout << "Everything is in order.\n";
	}
	else {
		std::cout << "Critical failure imminent.\n";
	}
}

Federation::Starfleet::Captain::Captain(std::string name)
{
	this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string	Federation::Starfleet::Captain::getName()
{
	return (this->_name);
}

int	Federation::Starfleet::Captain::getAge()
{
	return (this->_age);
}

void	Federation::Starfleet::Captain::setAge(int age)
{
	this->_age = age;
}

void	Federation::Starfleet::Ship::promote(Captain *Captain)
{
	this->_Captain = Captain;
	std::cout << this->_Captain->getName();
	std::cout << ": I'm glad to be the captain of the USS ";
	std::cout << this->_name << ".\n";
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
	this->_name = name;
	std::cout << "Ensign " << name << ", awaiting orders." << '\n';
}

Federation::Starfleet::Ensign::~Ensign()
{
}

bool	Borg::Ship::move(int warp, Destination d)
{
	if (warp <= this->_maxWarp && d != this->_location &&
		this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return (true);
	}
	else
		return (false);
}

bool	Borg::Ship::move(int warp)
{
	return (move(warp, this->_home));
}

bool	Borg::Ship::move(Destination d)
{
	return (move(this->_maxWarp, d));
}

bool	Borg::Ship::move()
{
	return (move(this->_maxWarp, this->_home));
}
