/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#include "ConveyorBeltRand.hpp"
#include "XML.hpp"
#include "Logger.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
}

bool ConveyorBeltRand::put(Object *obj)
{
	if (!obj || this->_occuped)
		return (false);
	this->_on = obj;
	this->_occuped = true;
	return (true);
}

Object* ConveyorBeltRand::take()
{
	Object *tmp;

	if (!this->_occuped)
		return (0);
	tmp = this->_on;
	this->_on = 0;
	this->_occuped = false;
	return (tmp);
}

void ConveyorBeltRand::IN()
{
	Object *in;
	int type = std::rand() % 3;

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
	if (!in)
		return ;
	this->put(in);
}

Object *ConveyorBeltRand::OUT()
{
	Object *obj = this->take();
	std::string content;

	if (obj) {
		content = XML::Serialize(obj);
		Logger::Export("cadeau1.xml", content);
	}
	return (obj);
}
