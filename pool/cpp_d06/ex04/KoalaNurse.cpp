/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        KoalaNurse.hpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(unsigned int id)
{
	this->nurseId = id;
	this->timeCheck();
}

KoalaNurse::~KoalaNurse()
{
	this->timeCheck();
	std::cout << "Nurse " << this->nurseId  << ": Finally some rest!";
	std::cout << std::endl;
}

void KoalaNurse::giveDrug(std::string name, SickKoala *patient)
{
	patient->takeDrug(name);
}

std::string KoalaNurse::readReport(std::string filename)
{
	std::string 	name(filename);
	std::ifstream	f(filename);
	std::string 	drugName("");
	std::size_t	pos;

	pos = name.find(".report");
	if (pos != std::string::npos)
		name.erase(pos, ((std::string)".report").length());
	if (f.is_open()) {
		getline(f, drugName);
		std::cout << "Nurse " << this->nurseId << ": Kreog ! Mr.";
		std::cout << name << " needs a " << drugName << "!"
		<< std::endl;
	}
	return (drugName);
}

void 	KoalaNurse::timeCheck()
{
	static unsigned int	clock = 0;

	std::cout << "Nurse " << this->nurseId << ": Time to g";
	if (clock == 0) {
		std::cout << "et to work!" << std::endl;
		clock++;
	}
	else {
		std::cout << "o home to my eucalyptus forest!";
		std::cout << std::endl;
		clock = 0;
	}
}
