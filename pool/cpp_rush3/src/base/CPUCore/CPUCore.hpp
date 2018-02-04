/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CoreModule.hpp
*/

#ifndef CPUCORE_HPP_
#define CPUCORE_HPP_

#include <string>
#include <ctime>

#ifdef __APPLE__
const char CPU_FREQ[] = "sysctl -n hw.cpufrequency";
const char CPU_NAME[] = "sysctl -n machdep.cpu.brand_string";
const char CPU_USAGE[] = "cat /proc/stat | grep cpu";
#else
const char CPU_FREQ[] = "cat /proc/cpuinfo | grep \"MHz\" | awk -F \": \" '{print $2}'";
const char CPU_USAGE[] = "cat /proc/stat | grep cpu";
const char CPU_NAME[] = "cat /proc/cpuinfo | grep \"model name\" | awk -F ':' '{print $2}' | tail -1";
#endif

class CPUCore
{
public:
	CPUCore(int);
	~CPUCore();

	std::string getName() const;
	float getUsage() const;
	float getFreq() const;
	float getCpuUsage();
	void setLoad(unsigned long &, unsigned long &, unsigned long &, unsigned long &);

private:
	std::string _name;
	int _id;
	int _freq;
	int _usage;
 	float _lastTotalUser;
	float _lastTotalNice;
	float _lastTotalSys;
	float _lastTotalIdle;
	float _lastTotalTime;

	clock_t _time;
};

#endif
