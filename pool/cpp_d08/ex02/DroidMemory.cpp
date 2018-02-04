/*
** EPITECH PROJECT, 2018
** cpp_d08
** File description:
**        DroidMemory.cpp
*/

#include <iostream>
#include <stdlib.h>
#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
	this->_Exp = 0;
	this->_FingerPrint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t	DroidMemory::getFingerPrint() const
{
	return (this->_FingerPrint);
}

void	DroidMemory::setFingerPrint(size_t finger)
{
	this->_FingerPrint = finger;
}

size_t	DroidMemory::getExp() const
{
	return (this->_Exp);
}

void	DroidMemory::setExp(size_t exp)
{
	this->_Exp = exp;
}

void DroidMemory::addXor(DroidMemory &dest, DroidMemory const &memory1,
	DroidMemory const &memory2)
{
	dest._Exp = memory1._Exp + memory2._Exp;
	dest._FingerPrint = memory1._FingerPrint ^ memory2._FingerPrint;
}

DroidMemory& DroidMemory::operator<<(DroidMemory const &memory)
{
	DroidMemory::addXor(*this, *this, memory);
	return (*this);
}

DroidMemory const & DroidMemory::operator>>(DroidMemory &memory) const
{
	DroidMemory::addXor(memory, *this, memory);
	return (memory);
}

DroidMemory& DroidMemory::operator+=(DroidMemory const &memory)
{
	return (this->operator<<(memory));
}

DroidMemory& DroidMemory::operator+=(size_t exp)
{
	this->_Exp += exp;
	this->_FingerPrint ^= exp;
	return (*this);
}

DroidMemory &DroidMemory::operator+(DroidMemory const &rhs)
{
	DroidMemory *tmp = new DroidMemory;

	tmp->_Exp += rhs._Exp;
	tmp->_FingerPrint ^= rhs._FingerPrint;
	return (*tmp);
}

DroidMemory &DroidMemory::operator+(size_t rhs) const
{
    DroidMemory *mem = new DroidMemory;

    mem->_Exp += rhs;
    mem->_FingerPrint ^= rhs;
    return (*mem);
}


std::ostream &operator<<(std::ostream &s, const DroidMemory &droid)
{
	return (s << "DroidMemory '" << droid.getFingerPrint() << "', "
	<< droid.getExp());
}

bool	DroidMemory::operator==(DroidMemory const &memory) const
{
	if (this->_Exp == memory._Exp &&
		this->_FingerPrint == memory._FingerPrint)
		return (true);
	else
		return (false);
}

bool	DroidMemory::operator!=(DroidMemory const &memory) const
{
	if (this->_Exp == memory._Exp &&
		this->_FingerPrint == memory._FingerPrint)
		return (false);
	else
		return (true);
}

bool DroidMemory::operator>(DroidMemory const &memory) const
{
	if (this->_Exp > memory._Exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator<(DroidMemory const &memory) const
{
	if (this->_Exp < memory._Exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator>=(DroidMemory const &memory) const
{
	if (this->_Exp >= memory._Exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator<=(DroidMemory const &memory) const
{
	if (this->_Exp <= memory._Exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator>(const size_t exp) const
{
	if (this->_Exp > exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator<(const size_t exp) const
{
	if (this->_Exp < exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator>=(const size_t exp) const
{
	if (this->_Exp >= exp)
		return (true);
	else
		return (false);
}

bool DroidMemory::operator<=(const size_t exp) const
{
	if (this->_Exp <= exp)
		return (true);
	else
		return (false);
}
