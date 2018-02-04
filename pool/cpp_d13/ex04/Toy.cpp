/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy()
	: type(BASIC_TOY), _name("toy")
{
}

Toy::Toy(ToyType ToyType, std::string const &name, std::string const &file)
	: type(ToyType), _name(name), _picture(file)
{
}

Toy::Toy(const Toy &copy)
	: type(copy.type), _name(copy._name), _picture(copy._picture)
{
}

Toy &Toy::operator=(const Toy &copy)
{
	if (this != &copy) {
		this->type = copy.type;
		this->_name = copy._name;
		this->_picture = copy._picture;
	}
	return (*this);
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

void	Toy::speak(std::string string)
{
	std::cout << _name << " \""<< string << "\"\n";
}

std::ostream &operator<<(std::ostream &s, const Toy &toy)
{
	return (s << toy.getName() << '\n' << toy.getAscii() << '\n');
}

Toy &Toy::operator<<(std::string const &put)
{
	_picture.data = put;
	return (*this);
}
