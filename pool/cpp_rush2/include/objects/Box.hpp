/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        GiftPaper.hpp
*/

#ifndef _BOX_
# define _BOX_

#include <string>
#include <cctype>
#include "Wrap.hpp"
#include "Object.hpp"

class Box : public Wrap
{
public:
	Box();
	virtual ~Box();
	virtual void closeMe();
	void wrapMeThat(Object *);
};

#endif
