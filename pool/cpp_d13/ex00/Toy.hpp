/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Toy.hpp
*/

#ifndef _TOY_
# define _TOY_

#include <string>
#include <cctype>
#include "Picture.hpp"

class Toy
{

public:
	enum ToyType
	{
		BASIC_TOY,
		ALIEN,
	};
	ToyType type;

public:
	Toy();
	Toy(ToyType ToyType, std::string name, std::string file);
	~Toy();
	int getType() const;
	std::string getName() const;
	void setName(std::string name);
	bool setAscii(std::string fileName);
	std::string getAscii() const;

private:
	std::string _name;
	Picture _picture;

};

#endif
