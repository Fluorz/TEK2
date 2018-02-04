/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _ACHARACTER_
# define _ACHARACTER_

#include <string>
#include <cctype>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
public:
	Character(const std::string &name);
	~Character();
	void recoverAP();
	void attack(AEnemy *enemy);
	std::string const &getName() const;
	bool action(int cost);
	int getAp() const;
	void equip(AWeapon* _AWeapon);
	AWeapon *getWeapon() const;
private:
	std::string _name;
	int _AP;
	AWeapon *_AWeapon;
};

std::ostream & operator<<(std::ostream & os, Character const & perso);

#endif
