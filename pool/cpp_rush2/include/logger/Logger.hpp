/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Logger.hpp
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>

class Logger
{
public:
	Logger();
	~Logger();

	static void Log(std::string const &);
	static void Export(std::string const &, std::string const &);
};

#endif
