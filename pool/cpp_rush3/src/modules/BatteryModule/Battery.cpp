/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Battery.cpp
*/

#include "Battery.hpp"

Battery::Battery()
{
	_battery = 0;
}

Battery::~Battery()
{
}

size_t Battery::getBattery()
{
	refresh();
	return (_battery);
}

std::string	Battery::getModuleName() const
{
	return ("BATTERY");
}

void	Battery::refresh()
{
	size_t batterie;
	std::stringstream input(std::stringstream::in | std::stringstream::out);
	input << CMD::Exec("upower -i $(upower -e | grep BAT) | grep --color=never -E \"percentage\" | awk -F \":\" '{print $2}'");

	input >> batterie;
	_battery = batterie;
}
