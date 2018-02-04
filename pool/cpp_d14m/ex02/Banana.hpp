/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Banana.hpp
*/

#ifndef _BANANA_
# define _BANANA_

#include <string>
#include "Fruit.hpp"

class Banana : public Fruit
{
public:
	Banana();
	~Banana();
	std::string getName() const;
	int getVitamins() const;
};
#endif
