/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        KoalaBot.hpp
*/

#ifndef _KOALABOT_
# define _KOALABOT_

#include <iostream>
#include <cctype>
#include "Parts.hpp"

class KoalaBot
{
	public:
	KoalaBot(const std::string &serial = "Bob-01");
	~KoalaBot();
	void setParts(Arms& _arms);
	void setParts(Legs& _legs);
	void setParts(Head& _head);
	void swapParts(Arms& _arms);
	void swapParts(Legs& _legs);
	void swapParts(Head& _head);
	void informations() const;
	bool status() const;
	private:
	std::string _serial;
	Arms _arms;
	Legs _legs;
	Head _head;
};

#endif
