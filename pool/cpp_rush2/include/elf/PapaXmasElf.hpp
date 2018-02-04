/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        PapaXmasElf.hpp
*/

#ifndef PAPAXMASELFT_HPP_
#define PAPAXMASELFT_HPP_

#include "Object.hpp"
#include "PapaXmasConvoyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "IElf.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class PapaXmasElf : public IElf
{
public:
	PapaXmasElf(ITable *, IConvoyorBelt *);
	~PapaXmasElf();
};

#endif
