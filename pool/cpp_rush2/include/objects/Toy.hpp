/*
** EPITECH PROJECT, 2018
** Toy
** File description:
**        Toy.hpp
*/

#ifndef TOY_HPP_
# define TOY_HPP_

#include <iostream>
#include <string>
#include "Object.hpp"

class	Toy : public	Object
{
public:
  Toy(std::string const &name);
  ~Toy();
  void		setname(std::string name);
  std::string	getname();
  virtual void	isTaken();
protected:
  std::string	_name;
  bool	_isTaken;
};

#endif /* TOY_HPP_ */
