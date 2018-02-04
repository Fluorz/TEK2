/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
	: _name(name), _damage(damage), _AP(apcost)
{
}

AWeapon::~AWeapon()
{
}

std::string const &AWeapon::getName() const
{
	return (_name);
}

int AWeapon::getAPCost() const
{
	return (_AP);
}

int AWeapon::getDamage() const
{
	return (_damage);
}
