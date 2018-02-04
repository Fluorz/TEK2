/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Temperature.cpp
*/

#include "Temperature.hpp"

Temperature::Temperature()
{
	_temperature = 0;
}

Temperature::~Temperature()
{
}

size_t	Temperature::getTemperature()
{
	refresh();
	return (_temperature);
}

std::string	Temperature::getModuleName() const
{
	return ("TEMPERATURE");
}

void	Temperature::refresh()
{
	size_t temperature;
	std::stringstream input(std::stringstream::in | std::stringstream::out);
	input << CMD::Exec("cat /sys/class/thermal/thermal_zone0/temp");

	input >> temperature;
	_temperature = temperature;
}
