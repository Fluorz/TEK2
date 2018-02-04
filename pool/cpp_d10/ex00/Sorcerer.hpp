/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Peon.hpp
*/

#ifndef _SORCERER_
# define _SORCERER_

#include <string>
#include <cctype>
#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	virtual ~Sorcerer();
	std::string getName() const;
	std::string getTitle() const;
	virtual void polymorph(const Victim &victim) const;

protected:
	std::string _name;
	std::string _title;
};

std::ostream &operator<<(std::ostream &s, const Sorcerer &sorcerer);

#endif
