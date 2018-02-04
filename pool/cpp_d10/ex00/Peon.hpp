/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Peon.hpp
*/

#ifndef _PEON_
# define _PEON_

#include <string>
#include <cctype>
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	virtual ~Peon();
	virtual void getPolymorphed() const;
};

#endif
