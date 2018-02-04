/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        Parts.hpp
*/

#ifndef _PARTS_
# define _PARTS_

#include <iostream>
#include <cctype>

class Arms
{
	public:
	Arms(const std::string &serial = "A-01", bool functional = true);
	~Arms();
	bool isFunctionnal() const;
	std::string serial() const;
	void informations() const;
	private:
	std::string _serial;
	bool _functional;
};

class Legs
{
	public:
	Legs(const std::string &serial = "L-01", bool functional = true);
	~Legs();
	bool isFunctionnal() const;
	std::string serial() const;
	void informations() const;
	private:
	std::string _serial;
	bool _functional;
};

class Head
{
	public:
	Head(const std::string &serial = "H-01", bool functional = true);
	~Head();
	bool isFunctionnal() const;
	std::string serial() const;
	void informations() const;
	private:
	std::string _serial;
	bool _functional;
};

#endif
