/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        CPUModule.hpp
*/

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "../../base/CPUCore/CPUCore.hpp"

#ifdef __APPLE__
const char CPU_CORENB[] = "sysctl machdep.cpu.core_count | awk -F \": \" '{print $2}'";
#else
const char CPU_CORENB[] = "cat /proc/cpuinfo | grep \"cores\" | wc -l";
#endif

class CPUModule
{
public:
	CPUModule();
	virtual ~CPUModule();

	CPUCore &getCore(int id) const;
	int getCoreNb() const;
	std::string getModuleName() const;

private:
	CPUCore **_cpuCore;
	int _coreNb;
};

#endif
