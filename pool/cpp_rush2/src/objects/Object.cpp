/*
** EPITECH PROJECT, 2018
** Object
** File description:
**        Object.cpp
*/

#include "Object.hpp"

Object::Object()
	: _type(OBJECT)
{
}

Object::~Object()
{
}

Object &Object::operator=(Object *r)
{
	return (*r);
}

std::ostream &operator<<(std::ostream &os, const Type &type)
{
	switch (type) {
		case LITTLEPONY:
			os << "LITTLEPONY";
		break;
		case TEDDY:
			os << "TEDDY";
		break;
		default:
		break;
	}
	return os;
}
