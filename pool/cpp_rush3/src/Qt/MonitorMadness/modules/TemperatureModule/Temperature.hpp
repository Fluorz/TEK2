/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Temperature.hpp
*/

#ifndef _TEMPERATURE_
# define _TEMPERATURE_

#include <iostream>
#include <sstream>
#include "../IMonitorModule.hpp"
#include "../../base/CMD/CMD.hpp"

class Temperature : public IMonitorModule
{
public:
	Temperature();
	virtual ~Temperature();
public:
	size_t getTemperature();
	void refresh();
	std::string getModuleName() const;
protected:
	size_t _temperature;
};

#endif
