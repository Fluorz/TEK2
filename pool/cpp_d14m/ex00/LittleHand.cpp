/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        LittleHand.cpp
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void	doNothing()
{
	return;
}

void	LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
	FruitBox &bananas, FruitBox &limes)
{
	FruitNode *_unsorted = unsorted.head();

	if (!_unsorted)
		return;
	while (_unsorted->next)
	{
		if (_unsorted->content->getVitamins() == 3 && _unsorted->content->getName().compare("lemons") && lemons.nbFruits() < lemons.getSize())
		{
			lemons.putFruit(_unsorted->content);
			unsorted.pickFruit();
		}
		else if (_unsorted->content->getVitamins() == 5 && _unsorted->content->getName().compare("bananas") && bananas.nbFruits() < bananas.getSize())
		{
			bananas.putFruit(_unsorted->content);
			unsorted.pickFruit();
		}
		else if (_unsorted->content->getVitamins() == 2 && _unsorted->content->getName().compare("limes") && limes.nbFruits() < limes.getSize())
		{
			limes.putFruit(_unsorted->content);
			unsorted.pickFruit();
		}
		else
			doNothing();
		_unsorted = _unsorted->next;
	}
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
	int i = 0;
	int current_len = 0;
	int number_coco = 0;
	int coco = 0;

	if (!coconuts)
		return (NULL);
	while (coconuts[i++]) {}
	i--;
	if (i == 0)
	{
		FruitBox ** pack = new FruitBox*[1];
		pack[0] = NULL;
		return (pack);
	}
	FruitBox ** pack = new FruitBox*[i / 6 + 2];
	pack[i / 6 + 1] = NULL;
	number_coco = i;
	i = 0;
	pack[0] = new FruitBox(6);
	while (i != number_coco)
	{
		if (current_len == 6)
		{
			current_len = 0;
			coco++;
			pack[coco] = new FruitBox(6);
		}
		else {
			pack[coco]->putFruit((const_cast<Coconut *>(const_cast<Coconut * const *>(coconuts)[i])));
			current_len++;
			i++;
		}
	}
	return (pack);
}
