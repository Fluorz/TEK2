/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        LittleHand.hpp
*/

#ifndef _LITTLEHAND_
# define _LITTLEHAND_

#include <string>
#include "FruitBox.hpp"

class LittleHand
{
public:
	LittleHand();
	~LittleHand();
	static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};

void doNothing();

#endif
