/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        KoalaDoctor.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "KoalaDoctor.hpp"
#include "SickKoala.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : name(name)
{
	std::cout << "Dr." << this->name << ": I'm Dr." << this->name
	<< "! How do you kreog?" << std::endl;
	this->timeCheck();
};

KoalaDoctor::~KoalaDoctor()
{
	this->timeCheck();
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
	std::ofstream 	f(patient->getName() + ".report");
	std::vector <std::string> drugs;

	drugs.push_back("mars");
	drugs.push_back("Buronzand");
	drugs.push_back("Viagra");
	drugs.push_back("Extasy");
	drugs.push_back("Eucalyptus leaf");
	std::cout << "Dr." << this->name << ": So what's goerking you Mr."
	<< patient->getName() << "?" << std::endl;
	patient->poke();
	f << drugs[random() % 5];
}

void 	KoalaDoctor::timeCheck()
{
	static unsigned int	clock = 0;

	std::cout << "Dr." << this->name << ": Time to g";
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

int main() {
	SickKoala ko("KO");
	KoalaDoctor maboul("Maboul");
	srand(time(NULL));
	maboul.diagnose(&ko);
}
