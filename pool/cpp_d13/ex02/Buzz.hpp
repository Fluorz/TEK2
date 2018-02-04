/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Buzz.hpp
*/

#ifndef _BUZZ_
# define _BUZZ_

#include <string>
#include <cctype>
#include "Toy.hpp"

class Buzz : public Toy
{
public:
	Buzz(std::string const &name);
	Buzz(std::string const &name, std::string const &filename);
	~Buzz();
};

#endif
