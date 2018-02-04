/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Fruit.hpp
*/

#ifndef _FRUIT_
# define _FRUIT_

#include <string>

class Fruit
{
public:
	Fruit(std::string const &name, int const vitamins);
	virtual ~Fruit();
	virtual std::string getName() const;
	virtual int getVitamins() const;
protected:
	std::string _name;
	int _vitamins;
};

#endif
