/*
** EPITECH PROJECT, 2018
** Teddy
** File description:
**        Teddy.cpp
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string const &name)
        : Toy(name)
{
  this->_type = TEDDY;
}

Teddy::~Teddy()
{
}

std::string	Teddy::getname()
{
  return (this->_name);
}

void     Teddy::setname(std::string name)
{
  this->_name =name;
}

void	Teddy::isTaken()
{
  this->_isTaken = true;
  std::cout << "gra hu" << std::endl;
}
