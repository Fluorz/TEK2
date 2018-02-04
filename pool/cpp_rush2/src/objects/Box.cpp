/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Box.cpp
*/

#include "Wrap.hpp"
#include "Box.hpp"

Box::Box()
	:  Wrap()
{
	this->_type = BOX;
}

Box::~Box()
{
}

void	Box::closeMe()
{
	Wrap::closeMe();
}

void	Box::wrapMeThat(Object *toy)
{
	Wrap::wrapMeThat(toy);
}
