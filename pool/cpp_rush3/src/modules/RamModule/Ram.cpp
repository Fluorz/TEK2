/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Ram.cpp
*/

#include <iostream>
#include "Ram.hpp"

Ram::Ram()
{
	_maxSwap = 0;
	_usedSwap = 0;
	_maxRam = 0;
	_usedRam = 0;
	_buffers = 0;
	_nbProcess = 0;
}

Ram::~Ram()
{
}

std::string Ram::getModuleName() const
{
	return std::string("RAM");
}

size_t	Ram::getMaxSwap()
{
	refresh();
	return (_maxSwap);
}

size_t	Ram::getUsedSwap()
{
	refresh();
	return (_usedSwap);
}

size_t	Ram::getMaxRam()
{
	refresh();
	return (_maxRam);
}

size_t	Ram::getUsedRam()
{
	refresh();
	return (_usedRam);
}

size_t	Ram::getBuffers()
{
	refresh();
	return (_buffers);
}

size_t	Ram::getNbProcess()
{
	refresh();
	return (_nbProcess);
}

#ifdef __APPLE__
void	Ram::refresh()
{
}
#else
void	Ram::refresh()
{
	struct sysinfo mem;
	sysinfo(&mem);
	_maxRam = mem.totalram;
	_usedRam = mem.totalram - mem.freeram;
	_buffers = mem.bufferram;
	_maxSwap = mem.totalswap;
	_usedSwap = mem.totalswap - mem.freeswap;
	_nbProcess = mem.procs;
}
#endif
