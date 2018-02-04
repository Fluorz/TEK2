/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        KoalaBot.cpp
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &serial)
{
	this->_serial = serial;
}

void	KoalaBot::setParts(Arms& arms)
{
	this->_arms = arms;
}

void	KoalaBot::setParts(Legs& legs)
{
	this->_legs = legs;
}

void	KoalaBot::setParts(Head& head)
{
	this->_head = head;
}

void KoalaBot::swapParts(Arms& arms) {
	setParts(arms);
}

void KoalaBot::swapParts(Legs& legs) {
	setParts(legs);
}

void KoalaBot::swapParts(Head& head) {
	setParts(head);
}

void KoalaBot::informations() const
{
	std::cout << "[KoalaBot] " << this->_serial << '\n';
	this->_arms.informations();
	this->_legs.informations();
	this->_head.informations();
}

bool KoalaBot::status() const
{
	return (this->_arms.isFunctionnal() &&
	 this->_legs.isFunctionnal() && this->_head.isFunctionnal());
}

KoalaBot::~KoalaBot()
{
}
