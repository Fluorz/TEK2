/*
** EPITECH PROJECT, 2021
** cpp_rush2
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH2_NPAPAXMASCONVOYORBELT_HPP
#define CPP_RUSH2_NPAPAXMASCONVOYORBELT_HPP

#include <random>

#include "IConvoyorBelt.hpp"

class PapaXmasConvoyorBelt : public IConvoyorBelt
{
	public:
	PapaXmasConvoyorBelt();
	~PapaXmasConvoyorBelt();

	public:
	bool put(Object*);
	Object *take();
	void IN();
	Object *OUT();
};

#endif //CPP_RUSH2_NPAPAXMASCONVOYORBELT_HPP
