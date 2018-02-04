/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Partitions.cpp
*/

#include "Partitions.hpp"

Partitions::Partitions()
{
	fill_partitions();
}

Partitions::~Partitions()
{
}

std::string Partitions::getModuleName() const
{
	return ("PARTITIONS");
}

int	Partitions::getNumber() const
{
	return (_number);
}

void	Partitions::fill_partitions()
{
	int i = 0;
	size_t size;
	std::string name;
	std::string cmd;

	std::stringstream input(std::stringstream::in | std::stringstream::out);
	cmd = "cut -c16-30 /proc/partitions | tail -11";
	input << CMD::Exec(cmd);

	while (i != 11)
	{
		input >> size >> name;
		_partitionsName[i] = name;
		_size[i] = size;
		i++;
	}
	_number = i;
}

std::string	Partitions::getPartitionsName(int id) const
{
	return (_partitionsName[id]);
}


size_t	Partitions::getSize(int id) const
{
	return (_size[id]);
}
