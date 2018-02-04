/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _SUPERMUTANT_
# define _SUPERMUTANT_

#include <string>
#include <cctype>
#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
public:
	SuperMutant();
	~SuperMutant();
	void takeDamage(int damage);
};
#endif
