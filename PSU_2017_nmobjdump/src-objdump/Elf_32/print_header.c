/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        print_header.c
*/

#include "../include/objdump.h"

static void 	print_adress(Elf32_Ehdr *elf)
{
	printf("\nstart address 0x%08x\n\n", (unsigned int)elf->e_entry);
}

static void 	print_header32(info_t *info)
{
	Elf32_Ehdr *tmp;

	tmp = info->data;
	printf("\n%s:     file format elf32-i386\narchitecture: i386",
	info->file);
	print_flags32(tmp);
	print_adress(tmp);
}

void elf32_format(info_t *info)
{
	print_header32(info);
	print_source32(info);
}
