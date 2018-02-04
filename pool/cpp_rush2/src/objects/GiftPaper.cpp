/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        GiftPaper.cpp
*/

#include <iostream>
#include "GiftPaper.hpp"

GiftPaper::GiftPaper()
	:  Wrap()
{
	this->_type = GIFTPAPER;
}

GiftPaper::~GiftPaper()
{
}

Object	*GiftPaper::takeMe()
{
	return (Wrap::takeMe());
}

void	GiftPaper::wrapMeThat(Object *toy)
{
	Wrap::wrapMeThat(toy);
}
