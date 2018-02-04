/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name)
	: _name(name), _AP(40), _AWeapon(NULL)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
	_AP += 10;
	if (_AP > 40) {
		_AP = 40;
	}
}

void Character::equip(AWeapon* _AWeapon)
{
	this->_AWeapon = _AWeapon;
}

void Character::attack(AEnemy* enemy)
{
	if (_AWeapon && enemy)
	{
		if (action(_AWeapon->getAPCost()))
		{
			std::cout << _name << " attacks " << enemy->getType() << " with a " << _AWeapon->getName() << std::endl;
			_AWeapon->attack();
			enemy->takeDamage(_AWeapon->getDamage());
			if (enemy->getHP() <= 0)
			{
				delete enemy;
			}
		}
	}
}

bool Character::action(int cost)
{
	if (_AP >= cost) {
		_AP -= cost;
		return true;
	}
	return false;
}

std::string const & Character::getName() const
{
	return _name;
}

int Character::getAp() const
{
	return (_AP);
}

AWeapon *Character::getWeapon() const
{
	return (_AWeapon);
}

std::ostream & operator<<(std::ostream & os, Character const & perso)
{
	os << perso.getName() <<  " has " << perso.getAp() << " AP and ";
	if (perso.getWeapon()) {
		os << "wields a " << perso.getWeapon()->getName();
	}
	else {
		os << "is unarmed";
	}
	os << std::endl;
	return os;
}
