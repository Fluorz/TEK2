/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        SickKoala.cpp
*/

#include <iostream>
#include <cctype>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string koalaName) : name(koalaName)
{
}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << this->name << ": Kreooogg !! I'm cuuuured!";
	std::cout << std::endl;
}

void SickKoala::poke()
{
	std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(";
	std::cout << std::endl;
}

static std::string 	nameToLowerCase(std::string &name)
{
	std::string 	temp(name);
	for (unsigned int i = 0; i < temp.length(); i++) {
		if (temp[i] >= 'A' && temp[i] <= 'Z')
			tolower(temp[i]);
	}
	return (temp);
}

bool SickKoala::takeDrug(std::string name)
{
	std::string	temp;
	bool 		retVal = true;

	temp = nameToLowerCase(name);
	if (name.compare("Buronzand") == 0) {
		std::cout << "Mr." << this->name <<
		": and you 'll sleep right away!";
		std::cout << std::endl;
	}
	else if (temp.compare("mars") == 0) {
		std::cout << "Mr." << this->name << ": Mars, and it kreogs!";
		std::cout << std::endl;
	}
	else {
		std::cout << "Mr." << this->name << ": Goerkreog!"
		<< std::endl;
		retVal = false;
	}
	return (retVal);
}

void SickKoala::overDrive(std::string text)
{
	std::string 	replace("1337!");
	std::size_t	posKroeg = 0;

	while (true) {
		posKroeg = text.find("Kreog!", posKroeg + 1);
		if (posKroeg != std::string::npos)
			text.replace(posKroeg, replace.length() + 1, replace);
		else
			break;
	}
	std::cout << "Mr." << this->name << ": ";
	std::cout << text << " How is it going?";
	std::cout << std::endl;
}
