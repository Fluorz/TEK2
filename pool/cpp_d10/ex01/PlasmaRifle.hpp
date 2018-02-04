/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _PLASMARIFLE_
# define _PLASMARIFLE_

#include <string>
#include <cctype>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	virtual void attack() const;
};

#endif
