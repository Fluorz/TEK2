/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        KoalaNurse.hpp
*/

#ifndef KOALANURSE_H_
#define KOALANURSE_H_

#include <iostream>
#include "SickKoala.hpp"

class KoalaNurse
{
public:
	KoalaNurse(unsigned int);
	~KoalaNurse();
	void giveDrug(std::string, SickKoala *);
	std::string readReport(std::string);
	void timeCheck();
private:
	unsigned int nurseId;
};

#endif
