/*
** EPITECH PROJECT, 2018
** cpp_d10
** File description:
**        Peon.hpp
*/

#ifndef _VICTIM_
# define _VICTIM_

#include <string>
#include <cctype>

class Victim
{
public:
	Victim(std::string name);
	virtual ~Victim();
	virtual std::string getName() const;
	virtual void getPolymorphed() const;
protected:
	std::string _name;
};

std::ostream &operator<<(std::ostream &s, const Victim &victim);

#endif
