/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#include "ITable.hpp"

// Constructors
ITable::ITable()
{
	for (int i = 0; i < 10; i += 1)
		this->_objs[i] = 0;
}

// Destructors
ITable::~ITable()
{
}

bool ITable::isArranged()
{
	for (int i = 0; i < 10; i += 1) {
		if (!this->_objs[i]) {
			for (; i < 10; i += 1)
				if (this->_objs[i])
					return (false);
		}
	}
	return (true);
}

void ITable::swapObjects(int  index, int index2)
{
	Object *tmp;

	if (index < 0 || index > 9 || index2 < 0 || index2 > 9)
		return ;
	tmp = this->_objs[index];
	this->_objs[index] = this->_objs[index2];
	this->_objs[index2] = tmp;
}

void ITable::arrangeObject()
{
	for (int i = 0; i < 9; i += 1) {
		if (!this->_objs[i] && this->_objs[i + 1]) {
			this->swapObjects(i, i + 1);
			this->arrangeObject();
		}

	}
}

int ITable::getIndex()
{
	int i;

	if (!this->isArranged())
		this->arrangeObject();
	for (i = 0; i < 10; i += 1)
		if (!this->_objs[i])
			return (i);
	return (i);
}
