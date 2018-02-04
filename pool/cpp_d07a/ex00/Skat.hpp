/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        Skat.hpp
*/

#include <string>
#include <iostream>
#include <cctype>

class Skat
{
	public:
	Skat (const std::string &name = "bob", int stimPaks = 15);
	~Skat();
	int &stimPaks();
	void shareStimPaks(int number, int &stock);
	const std::string &name();
	void addStimPaks (unsigned int number);
	void useStimPaks () ;
	void status () ;
	private:
	std::string _name;
	int _stimPaks;
};
