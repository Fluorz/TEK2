/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *\n";
}
