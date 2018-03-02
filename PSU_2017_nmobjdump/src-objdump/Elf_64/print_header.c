/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        print_header.c
*/

#include "../include/objdump.h"

static void 	print_adress(Elf64_Ehdr *elf)
{
	printf("\nstart address 0x%016x\n\n", (unsigned int)elf->e_entry);
}

static void 	print_header64(info_t *info)
{
	Elf64_Ehdr *tmp;

	tmp = info->data;
	printf("\n%s:     file format elf64-x86-64\narchitecture: i386:x86-64",
		info->file);
	print_flags64(tmp);
	print_adress(tmp);
}

void elf64_format(info_t *info)
{
	print_header64(info);
	print_source64(info);
}
