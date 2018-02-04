/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: AEnemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ...\n";
}

void SuperMutant::takeDamage(int damage)
{
	AEnemy::takeDamage(damage - 3);
}
