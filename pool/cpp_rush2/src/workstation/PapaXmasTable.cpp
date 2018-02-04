/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
}

PapaXmasTable::~PapaXmasTable()
{
}

// Members functions
bool PapaXmasTable::put(Object *obj)
{
	int index = this->getIndex();

	if ( index >= 10 || this->_objs[index])
		return (false);
	this->_objs[index] = obj;
	obj = 0;
	return (true);
}

Object* PapaXmasTable::take(int index)
{
	Object *tmp;

	if (index < 0 || index >= 10)
		return (0);
	tmp = this->_objs[index];
	this->_objs[index] = NULL;
	this->arrangeObject();
	std::cout << "whistles while working" << std::endl;
	return (tmp);
}

Object** PapaXmasTable::look()
{
	Object **objs = new Object*[11];

	for (int i = 0; i < 10; i += 1)
		objs[i] = this->_objs[i];
	objs[11] = 0;
	return (objs);
}
