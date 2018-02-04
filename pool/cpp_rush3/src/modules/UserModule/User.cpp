/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        User.cpp
*/

#include <sstream>
#include "CMD.hpp"
#include "User.hpp"

User::User()
{
	char *str;

	str = getenv("USER");
	if (str == NULL)
		exit (0);
	_userName = str;
	struct utsname info;
	uname(&info);
	_kernel = info.release;
	_osVersion = info.version;
	_machine = info.machine;
	_sysName = info.sysname;
}

User::~User()
{
}

std::string User::getModuleName() const
{
	return std::string ("USER");
}

time_t	User::getTime() const
{
	return (time(0));
}

#ifdef __APPLE__
time_t	User::getUpTime() const
{
	time_t temp = 0;
	std::stringstream ss;

	ss << CMD::Exec(USER_UPTIME);
	ss >> temp;
	return (temp);
}
#else
time_t	User::getUpTime() const
{
	time_t temp = 0;
	struct sysinfo info;

	sysinfo(&info);
	temp = info.uptime;
	return (temp);
}
#endif

std::string	User::getUserName() const
{
	return (_userName);
}

std::string	User::getKernel() const
{
	return (_kernel);
}

std::string	User::getOsVersion() const
{
	return (_osVersion);
}

std::string	User::getMachine() const
{
	return (_machine);
}

std::string	User::getSysName() const
{
	return (_sysName);
}
