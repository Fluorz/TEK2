/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        UnitTests.cpp
*/

#include <iostream>
#include "ConveyorBeltRand.hpp"
#include "PapaXmasElf.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConvoyorBelt.hpp"

ITable *createTable()
{
	return new PapaXmasTable;
}

IConvoyorBelt *createConvoyorTable()
{
	return new PapaXmasConvoyorBelt;
}

void XMLTest()
{
	ConveyorBeltRand belt;
	Toy *teddy = new Teddy("Winnie");

	belt.put(teddy);
	belt.OUT();
}

int main()
{
	// ITable *table = createTable();
	// IConvoyorBelt *conBelt = createConvoyorTable();
	// PapaXmasElf *elf = new PapaXmasElf(table, conBelt);
        //
	// elf->sendGift();
        //
	// delete table;
	// delete conBelt;
	// delete elf;
	// LittlePony *a = new LittlePony("poney gay");
	// Teddy *b = new Teddy("bisounours");
        //
	// Object **tab = new Object*[2];
        //
	// tab[0] = a;
	// tab[1] = b;
	// std::cout << "Tab[0] name = " << ((Toy *)tab[0])->getname() << " Tab[1] name = " << ((Toy*)tab[1])->getname() << std::endl;
	XMLTest();

	// Box *b = n;

	return 0;
}
