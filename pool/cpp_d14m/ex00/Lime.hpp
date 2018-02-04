/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Lime.hpp
*/

#ifndef _LIME_
# define _LIME_

#include <string>
#include "Lemon.hpp"

class Lime : public Lemon
{
public:
	Lime();
	~Lime();
	std::string getName() const;
	int getVitamins() const;
};

#endif
