/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Lemon.hpp
*/

#ifndef _LEMON_
# define _LEMON_

#include <string>
#include "Fruit.hpp"

class Lemon : public Fruit
{
public:
	Lemon();
	Lemon(std::string const &name, int const vitamins);
	virtual ~Lemon();
	virtual std::string getName() const;
	virtual int getVitamins() const;
};

#endif
