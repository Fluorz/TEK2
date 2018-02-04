/*
** EPITECH PROJECT, 2018
** LittlePony
** File description:
**        LittlePony.hpp
*/

#ifndef LittlePony_HPP_
# define LittlePony_HPP_

#include "Toy.hpp"

class	LittlePony : public	Toy
{
public:
  LittlePony(std::string const &name);
  ~LittlePony();
  void		setname(std::string name);
  std::string	getname();
  void		isTaken();
};

#endif /* LITTLEPONY_HPP_ */
