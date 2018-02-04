/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        User.hpp
*/

#ifndef _USER_
# define _USER_

#include <sys/utsname.h>
#include <cstdlib>
#ifdef __APPLE__
const char USER_UPTIME[] = "sysctl -n kern.boottime | cut -d \",\" -f 1 | cut -d \"=\" -f 2";
#else
#include <sys/sysinfo.h>
#endif
#include "../IMonitorModule.hpp"

class User : public IMonitorModule
{
public:
	User();
	virtual ~User();
public:
	time_t getTime() const;
	time_t getUpTime() const;
	std::string getUserName() const;
	std::string getKernel() const;
	std::string getOsVersion() const;
	std::string getMachine() const;
	std::string getSysName() const;

	std::string getModuleName() const;
protected:
	std::string _userName;
	std::string _kernel;
	std::string _osVersion;
	std::string _machine;
	std::string _sysName;
};

#endif
