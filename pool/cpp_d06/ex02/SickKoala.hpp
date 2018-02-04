/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        SickKoala.hpp
*/

#ifndef SICKKOALA_H_
#define SICKKOALA_H_

#include <string>

class SickKoala {
public :
	SickKoala(std::string);
	~SickKoala();
	void poke();
	bool takeDrug(std::string);
	void overDrive(std::string);
private :
	std::string name;
};

#endif
