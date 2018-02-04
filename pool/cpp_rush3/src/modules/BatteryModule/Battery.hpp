/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Battery.hpp
*/

#ifndef _BATTERY_
# define _BATTERY_

#include <iostream>
#include <sstream>
#include "IMonitorModule.hpp"
#include "CMD.hpp"

class Battery : public IMonitorModule
{
public:
	Battery();
	virtual ~Battery();
public:
	size_t getBattery();
	std::string getModuleName() const;
	void refresh();
protected:
	size_t _battery;
};

#endif
