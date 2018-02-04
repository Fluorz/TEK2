/*
** EPITECH PROJECT, 2018
** cpp_d09
** File description:
**        Character.hpp
*/

#ifndef _CHARACTER_
# define _CHARACTER_

#include <string>
#include <cctype>

typedef enum e_aRange
{
	aCLOSE,
	aRANGE
}		aRange;

class Character
{

public:
	const static aRange CLOSE = aCLOSE;
	const static aRange RANGE = aRANGE;

	aRange Range;

public:
	Character(const std::string &name = "Kreog", int level = 1);
	~Character();
	const std::string &getName() const;
	int getLvl() const;
	int getPv() const;
	int getPower() const;
	int CloseAttack();
	void Heal();
	int RangeAttack();
	void RestorePower();
	void TakeDamage(int);


protected:
	std::string	_name;
	int		_level;
	int		_pv;
	int		_energy;
	int		_Strength;
	int		_Stamina;
	int		_Intelligence;
	int		_Spirit;
	int		_Agility;
	std::string	_race;

};

#endif
