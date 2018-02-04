/*
** EPITECH PROJECT, 2018
** Object
** File description:
**        Object.hpp
*/

#ifndef OBJECT_HPP_
# define OBJECT_HPP_

#include <iostream>
#include <string>

enum Type {OBJECT, WRAP, BOX, GIFTPAPER, TOY, LITTLEPONY, TEDDY};

class	Object
{
	public:
  	Object();
  	~Object();
	Object &operator=(Object *);
	Type _type;
};

std::ostream &operator<<(std::ostream &, const Type &);

#endif /* OBJECT_HPP_ */
