/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        FruitNode.hpp
*/

#ifndef _FRUITNODE_
# define _FRUITNODE_

#include <string>
#include "Fruit.hpp"

class FruitNode
{
public:
	Fruit *content;
	FruitNode *next;
};

#endif
