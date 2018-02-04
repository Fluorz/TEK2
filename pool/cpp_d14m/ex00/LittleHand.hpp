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
#include "Coconut.hpp"

class LittleHand
{
public:
	LittleHand();
	~LittleHand();
	static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
	static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
};

void doNothing();

#endif
