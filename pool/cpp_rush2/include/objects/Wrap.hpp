/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        GiftPaper.hpp
*/

#ifndef _WRAP_
# define _WRAP_

#include <string>
#include <cctype>
#include "Object.hpp"

class Wrap : public Object
{
public:
	Wrap();
	~Wrap();
	virtual void wrapMeThat(Object *);
	virtual void openMe();
	virtual void closeMe();
	bool isOpen() const;
	virtual Object *takeMe();
protected:
	bool _opened;
	Object *_in;
};

#endif
