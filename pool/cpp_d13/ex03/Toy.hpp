/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Toy.hpp
*/

#ifndef _TOY_
# define _TOY_

#include <string>
#include <memory>
#include "Picture.hpp"

class Toy
{

public:
	enum ToyType
	{
		BASIC_TOY,
		ALIEN,
		BUZZ,
		WOODY
	};
	ToyType type;

public:
	Toy();
	Toy(const Toy&);
	Toy &operator=(const Toy&);
	Toy(ToyType ToyType, std::string const &name, std::string const &file);
	virtual ~Toy();
	int getType() const;
	std::string getName() const;
	void setName(std::string name);
	bool setAscii(std::string fileName);
	std::string getAscii() const;
	virtual void speak(std::string);

private:
	std::string _name;
	Picture _picture;

};

#endif
