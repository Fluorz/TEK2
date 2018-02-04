/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        KoalaDoctor.hpp
*/

#ifndef KOALADOCTOR_H_
#define KOALADOCTOR_H_

#include <iostream>
#include "SickKoala.hpp"

class KoalaDoctor
{
public:
	KoalaDoctor(std::string);
	~KoalaDoctor();
	void diagnose(SickKoala *);
	void timeCheck();

private:
	std::string name;
};

#endif
