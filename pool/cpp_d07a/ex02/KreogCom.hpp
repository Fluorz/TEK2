/*
** EPITECH PROJECT, 2018
** cpp_d07a
** File description:
**        KreogCom.hpp
*/

#ifndef _KREOGCOM_
# define _KREOGCOM_

#include <iostream>
#include <cctype>

class KreogCom
{
	public:
	KreogCom(int x, int y, int serial);
	~KreogCom();
	void addCom(int x, int y, int serial);
	KreogCom *getCom();
	void removeCom();
	void ping() const;
	void locateSquad() const;

	private:
	int _x;
	int _y;
	KreogCom *next;
	const int _serial;
};

#endif
