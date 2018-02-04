/*
** EPITECH PROJECT, 2018
** cpp_d08
** File description:
**        DroidMemory.hpp
*/

#ifndef _DROIDMEMORY_
# define _DROIDMEMORY_

#include <string>
#include <stdlib.h>
#include <cctype>

class DroidMemory
{
public:
	DroidMemory();
	~DroidMemory();
	size_t getFingerPrint() const;
	void setFingerPrint(size_t);
	size_t getExp() const;
	void setExp(size_t);

	static void addXor(DroidMemory &dest, DroidMemory const &memory1,
		DroidMemory const &memory2);

	DroidMemory &operator<<(DroidMemory const &memory);
	DroidMemory const  &operator>>(DroidMemory &memory) const;

	DroidMemory &operator+=(DroidMemory const &memory);
	DroidMemory &operator+=(size_t);

	DroidMemory &operator+(DroidMemory const &memory);
	DroidMemory &operator+(size_t) const;

private:
	size_t _FingerPrint;
	size_t _Exp;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &droid);

#endif
