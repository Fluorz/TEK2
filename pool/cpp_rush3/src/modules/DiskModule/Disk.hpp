/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Disk.hpp
*/

#ifndef _DISK_
# define _DISK_

#include <iostream>
#include <sstream>
#include "IMonitorModule.hpp"
#include "CMD.hpp"

class Disk : public IMonitorModule
{
public:
	Disk();
	virtual ~Disk();
public:
	void refresh();
	size_t getDiskRead();
	size_t getDiskWrite();
	std::string getModuleName() const;
protected:
	size_t _read;
	size_t _write;
};

#endif
