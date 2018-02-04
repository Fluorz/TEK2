/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH2_NICONVOYORBELT_HPP
#define CPP_RUSH2_NICONVOYORBELT_HPP

#include "Object.hpp"
#include "Toy.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class IConvoyorBelt
{
	public:
	IConvoyorBelt();
	virtual ~IConvoyorBelt();

	virtual bool put(Object *obj) = 0;
	virtual Object *take() = 0;
	virtual void IN() = 0;
	virtual Object *OUT() = 0;

	protected:
	bool _occuped;
	Object *_on;
};

#endif //CPP_RUSH2_NICONVOYORBELT_HPP
