/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Error.hpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

class Error
{
public:
	Error();
	~Error();

	static void Log(std::string const &);
	static void Log(std::string const &, std::string const &);
};

#endif
