/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy()
	: type(BASIC_TOY), _name("Toy")
{
}

Toy::Toy(ToyType ToyType, std::string name, std::string file)
	: type(ToyType), _name(name), _picture(file)
{
}

Toy::~Toy()
{
}

int	Toy::getType() const
{
	return (type);
}

std::string	Toy::getName() const
{
	return (_name);
}

void	Toy::setName(std::string name)
{
	_name = name;
}

bool	Toy::setAscii(std::string fileName)
{
	Picture Picture(fileName);

	if (Picture.getData() == "")
		return (false);
	else {
		_picture = Picture;
		return (true);
	}
}

std::string	Toy::getAscii() const
{
	return (this->_picture.getData());
}
