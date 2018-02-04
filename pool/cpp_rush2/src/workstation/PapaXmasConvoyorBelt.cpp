/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#include "PapaXmasConvoyorBelt.hpp"

PapaXmasConvoyorBelt::PapaXmasConvoyorBelt()
{
}

PapaXmasConvoyorBelt::~PapaXmasConvoyorBelt()
{
	if (this->_on)
		delete this->_on;
}

bool PapaXmasConvoyorBelt::put(Object *obj)
{
	if (!obj || this->_occuped)
		return (false);
	this->_on = obj;
	this->_occuped = true;
	return (true);
}

Object* PapaXmasConvoyorBelt::take()
{
	Object *tmp;

	if (!this->_occuped)
		return (0);
	tmp = this->_on;
	this->_on = 0;
	this->_occuped = false;
	return (tmp);
}

void PapaXmasConvoyorBelt::IN()
{
	Object *in;
	static int type = 0;

	switch (type) {
	case 0:
		in = new Box();
		break;
	case 1:
		in = new GiftPaper();
		break;
	case 2:
                if (std::rand() % 2)
			in = new Teddy("Teddy");
		else
			in = new LittlePony("LittlePony");
		break;
	}
	type += 1;
	this->put(in);
	type = type > 2 ? 0 : type;
}

Object *PapaXmasConvoyorBelt::OUT()
{
	return (this->take());
}
