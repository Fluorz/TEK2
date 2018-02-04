/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Disk.cpp
*/

#include "Disk.hpp"

Disk::Disk()
{
	_read = 0;
	_write = 0;
}

Disk::~Disk()
{
}

size_t	Disk::getDiskRead()
{
	refresh();
	return (_read);
}

size_t	Disk::getDiskWrite()
{
	refresh();
	return (_write);
}

std::string	Disk::getModuleName() const
{
	return ("DISK");
}

void	Disk::refresh()
{
	static time_t delay = time(0) + 1;
	size_t read;
	size_t write;
	size_t blank;

	if (time(0) == delay)
		return;
	std::stringstream input(std::stringstream::in | std::stringstream::out);
	input << CMD::Exec("cat /sys/block/sda/stat");

	input >> read >> blank >> blank >> blank >> write;
	_read = read;
	_write = write;
	delay = time(0) + 1;
}
