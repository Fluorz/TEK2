/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _POWERFIST_
# define _POWERFIST_

#include <string>
#include <cctype>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	virtual ~PowerFist();
	virtual void attack() const;
};

#endif
