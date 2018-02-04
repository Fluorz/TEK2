/*
** EPITECH PROJECT, 2018
** Teddy
** File description:
**        Teddy.hpp
*/

#ifndef TEDDY_HPP_
# define TEDDY_HPP_

#include "Toy.hpp"

class	Teddy : public	Toy
{
public:
  Teddy(std::string const &name);
  ~Teddy();
  void		setname(std::string name);
  std::string	getname();
  void		isTaken();
};

#endif /* TEDDY_HPP_ */
