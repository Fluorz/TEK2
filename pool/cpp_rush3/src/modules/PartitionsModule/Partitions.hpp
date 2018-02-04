/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Partitions.hpp
*/

#ifndef _PARTITIONS_
# define _PARTITIONS_

#include <iostream>
#include <sstream>
#include "IMonitorModule.hpp"
#include "CMD.hpp"

class Partitions : public IMonitorModule
{
public:
	Partitions();
	virtual ~Partitions();
public:
	std::string getPartitionsName(int id) const;
	int getNumber() const;
	size_t getSize(int id) const;
	std::string getModuleName() const;
	void fill_partitions();
protected:
	std::string _partitionsName[11];
	int	_number;
	size_t	_size[11];
};

#endif
