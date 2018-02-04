/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
	: _type(type), _hp(hp)
{
}

AEnemy::~AEnemy()
{
}

void	AEnemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	else {
		_hp -= damage;
	}

}

std::string const &AEnemy::getType() const
{
	return (_type);
}

int AEnemy::getHP() const
{
	return (_hp);
}
