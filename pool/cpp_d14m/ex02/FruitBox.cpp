/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int _size)
	:  list(NULL), _size(_size), _number(0)
{
}

FruitBox::~FruitBox()
{
}

int	FruitBox::nbFruits()
{
	return (_number);
}

bool	FruitBox::putFruit(Fruit *f)
{
	if (_number < _size && f != NULL)
	{
		FruitNode *current = list;
		FruitNode *node = new FruitNode();
		node->content = f;
		if (!list)
			list = node;
		else
		{
			if (current->content == f)
				return (false);
			while (current->next)
			{
				if (current->content == f)
					return (false);
				current = current->next;
			}
			current->next = node;
		}
		_number++;
		return (true);
	}
	return (false);
}

Fruit	*FruitBox::pickFruit()
{
	if (!list)
		return (NULL);
	Fruit *tmp = list->content;
	list = list->next;
	_number--;
	return (tmp);
}

FruitNode *FruitBox::head() const
{
	return (list);
}

int	FruitBox::getSize()
{
	return (_size);
}
