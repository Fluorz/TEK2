/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH2_NPAPAXMASTABLE_HPP
#define CPP_RUSH2_NPAPAXMASTABLE_HPP

#include "ITable.hpp"
#include <cstdlib>

class PapaXmasTable : public ITable
{
	public:
	PapaXmasTable();
	~PapaXmasTable();

	public:
	bool put(Object *obj);
	Object *take(int index);
	Object **look();

};

#endif //CPP_RUSH2_NPAPAXMASTABLE_HPP
