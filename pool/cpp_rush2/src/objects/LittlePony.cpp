/*
** EPITECH PROJECT, 2018
** LittlePony
** File description:
**        LittlePony.cpp
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string const &name)
        : Toy(name)
{
  this->_type = LITTLEPONY;
}

LittlePony::~LittlePony()
{
}

std::string	LittlePony::getname()
{
  return (this->_name);
}

void     LittlePony::setname(std::string name)
{
  this->_name =name;
}

void	LittlePony::isTaken()
{
  this->_isTaken = true;
  std::cout << "ya man" << std::endl;
}
