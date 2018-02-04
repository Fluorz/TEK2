/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        KreogCom.cpp
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
	: _x(x), _y(y), _serial(serial)
{
	next = NULL;
	std::cout << "KreogCom " << this->_serial << " initialized" << '\n';
}

KreogCom::~KreogCom()
{
	std::cout << "KreogCom " << this->_serial << " shutting down" << '\n';
}

void KreogCom::addCom(int x, int y, int serial)
{
	KreogCom *next = new KreogCom(x, y, serial);

	if (!this->next) {
		this->next = next;
	}
	else {
		next->next = this->next;
		this->next = next;
	}
}

KreogCom *KreogCom::getCom()
{
	return next;
}

void KreogCom::removeCom()
{
	KreogCom *del;
	if (next) {
		del = next;
		next = next->next;
		delete del;
	}
}

void KreogCom::ping() const
{
	std::cout << "KreogCom " << this->_serial << " currently at ";
	std::cout << this->_x << " " << this->_y << '\n';
}

void KreogCom::locateSquad() const
{
	KreogCom *current = this->next;

	while (current) {
		current->ping();
		current = current->getCom();
	}
	this->ping();
}
