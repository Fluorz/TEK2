/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        Parts.cpp
*/

#include "Parts.hpp"

Arms::Arms(const std::string &serial, bool functional)
{
	this->_serial = serial;
	this->_functional = functional;
}

Arms::~Arms()
{
}

bool	Arms::isFunctionnal() const
{
	return (this->_functional);
}

std::string	Arms::serial() const
{
	return (this->_serial);
}

void	Arms::informations() const
{
	std::cout << "\t[Parts] Arms ";
	std::cout << this->_serial;
	std::cout << " ";
	std::cout << "status : ";
	if (this->_functional == true) {
		std::cout << "OK\n";
	}
	else {
		std::cout << "KO\n";
	}
}

Legs::Legs(const std::string &serial, bool functional)
{
	this->_serial = serial;
	this->_functional = functional;
}

bool	Legs::isFunctionnal() const
{
	return (this->_functional);
}

std::string	Legs::serial() const
{
	return (this->_serial);
}

void	Legs::informations() const
{
	std::cout << "\t[Parts] Legs ";
	std::cout << this->_serial;
	std::cout << " ";
	std::cout << "status : ";
	if (this->_functional == true) {
		std::cout << "OK\n";
	}
	else {
		std::cout << "KO\n";
	}
}

Legs::~Legs()
{
}

Head::Head(const std::string &serial, bool functional)
{
	this->_serial = serial;
	this->_functional = functional;
}

bool	Head::isFunctionnal() const
{
	return (this->_functional);
}

std::string	Head::serial() const
{
	return (this->_serial);
}

void	Head::informations() const
{
	std::cout << "\t[Parts] Head ";
	std::cout << this->_serial;
	std::cout << " ";
	std::cout << "status : ";
	if (this->_functional == true) {
		std::cout << "OK\n";
	}
	else {
		std::cout << "KO\n";
	}
}

Head::~Head()
{
}
