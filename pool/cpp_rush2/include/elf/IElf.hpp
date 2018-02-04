/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        IElf.hpp
*/

#ifndef IEFL_HPP_
#define IEFL_HPP_

#include "Object.hpp"
#include "IConvoyorBelt.hpp"
#include "ITable.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class IElf
{
public:
	IElf(ITable *, IConvoyorBelt *);
	virtual ~IElf() = 0;
	virtual void sendGift();
protected:
	ITable *_table;
	IConvoyorBelt *_conBelt;

private:
	void getObjectToTable(Object *);
	void wrapToFinalObject();
};

#endif
