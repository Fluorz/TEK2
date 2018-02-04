/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        Logger.cpp
*/

#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include "Logger.hpp"

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::Log(std::string const &msg)
{
	std::cout << msg << std::endl;
}

void Logger::Export(std::string const &fileName, std::string const &data)
{
	std::ofstream fi("files/XML/" + fileName);

	fi << data << std::endl;
	fi.close();
}
