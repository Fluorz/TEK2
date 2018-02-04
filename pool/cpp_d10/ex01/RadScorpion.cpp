/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
	: AEnemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}
