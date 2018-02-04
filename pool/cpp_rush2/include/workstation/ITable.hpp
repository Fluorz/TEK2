/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH2_NITABLE_HPP
#define CPP_RUSH2_NITABLE_HPP

#include "../objects/Object.hpp"

class ITable
{
	public:
	ITable();
	virtual ~ITable();

	public:
	virtual bool put(Object *) = 0;
	virtual Object *take(int index) = 0;
	virtual Object **look() = 0;

	protected:
	int getIndex();
	bool isArranged();
	void swapObjects(int  index, int index2);
	void arrangeObject();

	protected:
	Object *_objs[10];
};

#endif //CPP_RUSH2_NITABLE_HPP
