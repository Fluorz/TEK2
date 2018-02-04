/*
** EPITECH PROJECT, 2018
** Toy
** File description:
**        Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy(std::string const &name)
{
  this->_type = TOY;
  this->_name = name;
  this->_isTaken = false;
}

Toy::~Toy()
{
}

void     Toy::setname(std::string name)
{
  this->_name = name;
}

std::string     Toy::getname()
{
  return (this->_name);
}

void	Toy::isTaken()
{
  this->_isTaken = true;
}
