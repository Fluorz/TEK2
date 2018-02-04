/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CMD.cpp
*/

#include <fstream>
#include <cstdlib>
#include <sstream>
#include "CMD.hpp"

#include <iostream>

std::string CMD::Exec(const std::string &command)
{
	std::string cmd;
	std::string tmp = command;
	std::fstream f("/tmp/rush.3",
	std::fstream::in | std::fstream::out | std::fstream::trunc);

	tmp += " > /tmp/rush.3";
	if (system(tmp.data()) < 0) {
		return std::string("");
	}
	if (f.is_open()) {
		std::stringstream ss;
		ss << f.rdbuf();
		cmd = ss.str();
		f.close();
		remove("/tmp/rush.3");
		return cmd;
	}
	return std::string("");
}
