/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH2_TABLERAND_HPP
#define CPP_RUSH2_TABLERAND_HPP

#include "ITable.hpp"

class TableRand : public ITable
{
	public:
	TableRand();
	~TableRand();

	public:
	bool put(Object *obj);
	Object *take(int index);
	Object **look();
};

#endif //CPP_RUSH2_TABLERAND_HPP
