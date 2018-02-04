/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CPUCore.cpp
*/

#include <sstream>
#include "CPUCore.hpp"
#include "base/Maths/Maths.hpp"
#include "base/CMD/CMD.hpp"

#include <iostream>

CPUCore::CPUCore(int id)
{
	_id = id;
	_name = CMD::Exec(CPU_NAME);
	_lastTotalUser = 0;
	_lastTotalNice = 0;
	_lastTotalSys = 0;
	_lastTotalIdle = 0;
	_usage = this->getCpuUsage();
	_time = clock();
}

CPUCore::~CPUCore()
{
}

/*
** @params {user nice sys idle} caught from CMD
** set CPUCore _last* to current;
*/
void CPUCore::setLoad(unsigned long &user, unsigned long &nice, unsigned long &sys, unsigned long &idle)
{
	_lastTotalUser = user;
	_lastTotalNice = nice;
	_lastTotalSys = sys;
	_lastTotalIdle = idle;
}

/*
** @return percentage of [CPU + _id] usage
** updates every SECONDS
*/
float CPUCore::getCpuUsage()
{
    #ifdef __APPLE__
    return 0;
    #else
	std::string cpu;
	unsigned long usg, totalCPUUsage, user, nice, sys, idle, iowait,
	irq, softirq;
	std::string cmd = std::string(CPU_USAGE) + (char) (_id + 48);
	std::stringstream ss, ssavg;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle >> iowait >> irq
	>> softirq;
	totalCPUUsage = user + sys + idle;
	usg = (user * 100) / (totalCPUUsage);
	// totalCPUUsage = (user - _lastTotalUser) +
	// (nice - _lastTotalNice) + (sys - _lastTotalSys);
	// usg = totalCPUUsage;
	// totalCPUUsage += (idle - _lastTotalIdle);
	// usg /= totalCPUUsage;
	// usg *= 100;
	this->setLoad(user, nice, sys, idle);
	_time = clock();
	return (float) usg;
    #endif
}

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
