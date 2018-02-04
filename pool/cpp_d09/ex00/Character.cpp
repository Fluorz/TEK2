/*
** EPITECH PROJECT, 2018
** cpp_d09
** File description:
**        Character.cpp
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
	_name = name;
	_level = level;
	_pv = 100;
	_energy = 100;
	_Strength = 5;
	_Stamina = 5;
	_Intelligence = 5;
	_Spirit = 5;
	_Agility = 5;
	Range = CLOSE;
	std::cout << _name << " Created\n";
}

Character::~Character()
{
}

int	Character::getLvl() const
{
	return (this->_level);
}

int	Character::getPv() const
{
	return (this->_pv);
}

int	Character::getPower() const
{
	return (this->_energy);
}

int	Character::CloseAttack()
{
	int damage = 0;

	if (_energy < 10) {
		std::cout << _name << " out of power\n";
		return (0);
	}
	else {
		_energy -= 10;
		damage += _Strength + 10;
		std::cout << _name << " strikes with a wooden stick\n";
		return (damage);
	}
}

void	Character::Heal()
{
	_pv += 50;
	std::cout << _name << " takes a potion\n";
}

int	Character::RangeAttack()
{
	int damage = 0;

	if (_energy < 10) {
		std::cout << _name << " out of power\n";
		return (0);
	}
	else {
		_energy -= 10;
		damage += _Strength + 5;
		std::cout << _name << " tosses a stone\n";
		return (damage);
	}
}

void	Character::RestorePower()
{
	_pv += 100;
	std::cout << _name << " eats\n";
}

void	Character::TakeDamage(int damage)
{
	_pv -= damage;
	if (_pv <= 0) {
		std::cout << _name << " out of combat\n";
		return;
	}
	std::cout << _name << " takes " << damage << " damage\n";
}
