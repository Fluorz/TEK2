/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#include "TableRand.hpp"

TableRand::TableRand()
{
}

TableRand::~TableRand()
{
}

// Members functions
bool TableRand::put(Object *obj)
{
	int index = this->getIndex();

	if ( index >= 10 || this->_objs[index])
		return (false);
	this->_objs[index] = obj;
	obj = 0;
	return (true);
}

Object* TableRand::take(int index)
{
	Object *tmp;

	if (index < 0 || index >= 10)
		return (0);
	tmp = this->_objs[index];
	this->_objs[index] = 0;
	this->arrangeObject();
	return (tmp);
}

Object** TableRand::look()
{
	Object **objs = new Object*[11];

	for (int i = 0; i < 10; i += 1)
		objs[i] = this->_objs[i];
	objs[11] = 0;
	return (objs);
}