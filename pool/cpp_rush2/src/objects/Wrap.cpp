/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Wrap.cpp
*/

#include <iostream>
#include "Wrap.hpp"

Wrap::Wrap()
	: Object(), _opened(false), _in(NULL)
{
	this->_type = WRAP;
}

Wrap::~Wrap()
{
}

void	Wrap::wrapMeThat(Object *toy)
{
	std::cout << "Tuuut tuuut tuut" << std::endl;
	_in = toy;
}

void	Wrap::openMe()
{
	_opened = true;
}

void	Wrap::closeMe()
{
	_opened = false;
}

bool	Wrap::isOpen() const
{
	return (_opened);
}

Object	*Wrap::takeMe()
{
	return (_in);
}
