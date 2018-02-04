/*
** EPITECH PROJECT, 2018
** test_criterion
** File description:
**        unit_test.c
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>
#include "PapaXmasElf.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConvoyorBelt.hpp"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

ITable *createTable()
{
	return new PapaXmasTable;
}

IConvoyorBelt *createConvoyorTable()
{
	return new PapaXmasConvoyorBelt;
}

void	to_test()
{
	ITable *table = createTable();
	IConvoyorBelt *conBelt = createConvoyorTable();
	PapaXmasElf *elf = new PapaXmasElf(table, conBelt);

	elf->sendGift();
}

Test (coco, nom_du_test, .init= redirect_all_std)
{
	to_test();
	cr_assert_stdout_eq_str("gra hu\n");
}
