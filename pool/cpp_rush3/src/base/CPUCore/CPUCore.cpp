/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CPUCore.cpp
*/

#include <sstream>
#include <unistd.h>
#include "CPUCore.hpp"
#include "Maths.hpp"
#include "CMD.hpp"

#include <iostream>

CPUCore::CPUCore(int id)
{
	_id = id;
	_name = CMD::Exec(CPU_NAME);
	_name[_name.size() - 1] = '\0';
	_lastTotalUser = 0;
	_lastTotalNice = 0;
	_lastTotalSys = 0;
	_lastTotalIdle = 0;
	_lastTotalTime = 0;
	_usage = this->getCpuUsage();
	_time = clock();
}

CPUCore::~CPUCore()
{
}

#ifdef __APPLE__
float CPUCore::getCpuUsage()
{
	return 0;
}
#else
float CPUCore::getCpuUsage()
{
	static float lastUser, lastNice, lastSys, lastIdle = 0;
	float user, nice, sys, idle, totalUsgTime, usg, totalTimeOverall = 0;
	std::string cpu;
	std::string cmd = std::string(CPU_USAGE) + (char) (_id + 48);
	std::stringstream ss;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle;
	totalUsgTime = (user - lastUser) + (nice - lastNice) + (sys - lastSys);

	totalTimeOverall = totalUsgTime + (idle - lastIdle);

	usg = (100.0 * totalUsgTime) / totalTimeOverall;
	if (usg < 0 || usg > 100)
		return -1;
	lastUser = user;
	lastNice = nice;
	lastSys = sys;
	lastIdle = idle;
	return (usg);
}
#endif

std::string CPUCore::getName() const
{
 	return _name;
}

float CPUCore::getUsage() const
{
	return _usage;
}

float CPUCore::getFreq() const
{
	std::stringstream temp;
	float _freq = 0;

	temp  << CMD::Exec(CPU_FREQ);
	temp >> _freq;
	return _freq;
}
