/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Woody.hpp
*/

#ifndef _WOODY_
# define _WOODY_

#include <string>
#include <cctype>
#include "Toy.hpp"

class Woody : public Toy
{
public:
	Woody(std::string const &name);
	Woody(std::string const &name, std::string const &filename);
	~Woody();
};

#endif
