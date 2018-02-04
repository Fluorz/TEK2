/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        IElf.cpp
*/

#include <iostream>
#include "IElf.hpp"
#include "Error.hpp"

IElf::IElf(ITable *table, IConvoyorBelt *cb)
{
	this->_table = table;
	this->_conBelt = cb;
}

IElf::~IElf()
{
}

void IElf::getObjectToTable(Object *obj)
{
	this->_conBelt->IN();
	obj = this->_conBelt->take();
	this->_table->put(obj);
}

void IElf::wrapToFinalObject()
{
	Toy *toy = (Toy *)this->_table->take(2);
	Box *box = (Box *)this->_table->take(0);
	GiftPaper *giftpaper = (GiftPaper *)this->_table->take(0);

	if ((toy->_type == TEDDY || toy->_type == LITTLEPONY) &&
	box->_type == BOX && giftpaper->_type == GIFTPAPER) {
		box->openMe();
		toy->isTaken();
		box->takeMe();
		box->wrapMeThat(toy);
		box->closeMe();
		giftpaper->wrapMeThat(box);
		this->_conBelt->put(giftpaper->takeMe());
		this->_conBelt->OUT();
	}
	else
		Error::Log("Making objects failed. Bad order.", "error.log");
}

// Box, Giftpaper, random(pony, teddy)
void IElf::sendGift()
{
	Object *obj = NULL;

	this->getObjectToTable(obj);
	this->getObjectToTable(obj);
	this->getObjectToTable(obj);
	this->wrapToFinalObject();
}
