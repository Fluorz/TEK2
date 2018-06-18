/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        processus.hpp
*/

#ifndef __PROCESSUS__
# define __PROCESSUS__

#include <string>
#include "plazza.hpp"

class Processus
{
public:
	Processus();
	~Processus();
	int getNbrProcessus();
	void setNbrProcessus();

	void execCommandFromVector(std::vector<std::string>);
private:
	int	_nbrProcessus;
};

#endif
