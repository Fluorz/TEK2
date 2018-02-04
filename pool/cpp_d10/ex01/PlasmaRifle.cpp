/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *\n";
}
