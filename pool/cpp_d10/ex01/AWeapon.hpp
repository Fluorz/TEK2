/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _AWEAPON_
# define _AWEAPON_

#include <string>
#include <cctype>

class AWeapon
{
public:
	AWeapon(const std::string &name, int apcost, int damage);
	virtual ~AWeapon();
	std::string const & getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
private:
	std::string _name;
	int	_damage;
	int	_AP;
};

#endif
