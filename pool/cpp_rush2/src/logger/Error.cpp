/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Error.cpp
*/

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include "Error.hpp"

Error::Error()
{
}

Error::~Error()
{
}

void Error::Log(std::string const &msg)
{
	std::cerr << msg << std::endl;
}

void Error::Log(std::string const &msg, std::string const &fileName)
{
	std::ofstream fi("files/log/" + fileName);

	std::cerr << msg << std::endl;
	fi << msg << std::endl;
	fi.close();
}
