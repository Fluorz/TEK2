/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        IMonitorModule.hpp
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>

class IMonitorModule
{
public:
	virtual std::string getModuleName() const = 0;
};

#endif
