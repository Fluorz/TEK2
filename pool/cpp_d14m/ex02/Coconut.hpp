/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Coconut.hpp
*/

#ifndef _COCONUT_
# define _COCONUT_

#include "Fruit.hpp"

class Coconut : public Fruit
{
public:
	Coconut();
	virtual ~Coconut();
	std::string getName() const;
	int getVitamins() const;
};

#endif
