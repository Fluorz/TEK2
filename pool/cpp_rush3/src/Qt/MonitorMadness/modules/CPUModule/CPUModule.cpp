/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CPUModule.cpp
*/

#include <string>
#include <exception>
#include <sstream>
#include <iostream>
#include "base/CMD/CMD.hpp"
#include "CPUModule.hpp"

CPUModule::CPUModule()
{
	std::stringstream ss(CMD::Exec(CPU_CORENB));
	ss >> _coreNb;
	_cpuCore = new CPUCore*[_coreNb];
	for (int i = 0; i < _coreNb; i++)
		_cpuCore[i] = new CPUCore(i);
}

CPUModule::~CPUModule()
{
	if (_cpuCore) {
		for (int i = 0; i < _coreNb; i++) {
			delete _cpuCore[i];
		}
		delete _cpuCore;
	}
}

CPUCore &CPUModule::getCore(int id) const
{
	if (id >= 0 && id < _coreNb)
		return *(_cpuCore[id]);
	throw std::exception();
}

int CPUModule::getCoreNb() const
{
	return _coreNb;
}

std::string	CPUModule::getModuleName() const
{
	return ("CPU");
}
