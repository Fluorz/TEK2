/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        AEnemy.hpp
*/

#ifndef _AENEMY_
# define _AENEMY_

#include <string>
#include <cctype>

class AEnemy
{
public:
	AEnemy(int hp, const std::string &type);
	virtual ~AEnemy();

	virtual void takeDamage(int damage);

	std::string const &getType() const;
	int getHP() const;

protected:

	std::string _type;
	int	_hp;
};
#endif
