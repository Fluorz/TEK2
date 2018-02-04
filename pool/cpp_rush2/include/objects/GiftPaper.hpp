/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        GiftPaper.hpp
*/

#ifndef _GIFTPAPER_
# define _GIFTPAPER_

#include <string>
#include <cctype>
#include "Wrap.hpp"
#include "Object.hpp"

class GiftPaper : public Wrap
{
public:
	GiftPaper();
	virtual ~GiftPaper();
	Object *takeMe();
	void wrapMeThat(Object *);
};

#endif
