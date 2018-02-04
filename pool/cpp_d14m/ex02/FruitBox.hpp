/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        FruitBox.hpp
*/

#ifndef _FRUITBOX_
# define _FRUITBOX_

#include <string>
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
public:
	FruitBox(int size);
	~FruitBox();
	int nbFruits();
	bool putFruit(Fruit *f);
	Fruit *pickFruit();
	FruitNode *head() const;
	int getSize();
private:
	FruitNode *list;
	int	_size;
	int	_number;
};

#endif
