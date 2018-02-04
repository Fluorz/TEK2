/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
	this->_name = name;
	this->_stimPaks = stimPaks;
}

Skat::~Skat()
{
}

int	&Skat::stimPaks()
{
	return (this->_stimPaks);
}

const std::string &Skat::name()
{
	return (this->_name);
}

void	Skat::shareStimPaks(int number, int &stock)
{
	if (number <= this->_stimPaks) {
		stock += number;
		this->_stimPaks -= number;
		std::cout << "Keep the change.\n";
	}
	else {
		std::cout << "Don't be greedy\n";
	}
}

void	Skat::addStimPaks(unsigned int number)
{
	if (number == 0) {
		std::cout << "Hey boya, did you forget something?\n";
	}
	this->_stimPaks += number;
}

void	Skat::useStimPaks()
{
	if (this->_stimPaks == 0) {
		std::cout << "Mediiiiiic\n";
	}
	else {
		this->_stimPaks -= 1;
		std::cout << "Time to kick some ass and chew bubble gum.\n";
	}
}

void	Skat::status()
{
	std::cout << "Soldier ";
	std::cout << this->_name << " ";
	std::cout << "reporting ";
	std::cout << this->_stimPaks << " ";
	std::cout << "stimpaks remaining sir!\n";
}
