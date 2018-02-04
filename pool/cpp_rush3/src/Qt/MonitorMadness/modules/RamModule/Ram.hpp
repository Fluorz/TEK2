/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Ram.hpp
*/

#ifndef _RAM_
# define _RAM_

#include "../IMonitorModule.hpp"
#ifdef __APPLE__
#else
#include "sys/sysinfo.h"
#endif

class Ram : public IMonitorModule
{
public:
	Ram();
	virtual ~Ram();
	void	refresh();
public:
	size_t getMaxSwap();
	size_t getUsedSwap();
	size_t getMaxRam();
	size_t getUsedRam();
	size_t getBuffers();
	size_t getNbProcess();

	std::string getModuleName() const;
protected:
	size_t	_maxSwap;
	size_t	_usedSwap;
	size_t	_maxRam;
	size_t	_usedRam;
	size_t	_buffers;
	size_t  _nbProcess;

};

#endif
