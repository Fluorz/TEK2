/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        other.c
*/

#include "../include/objdump.h"

int check_section(Elf64_Shdr section)
{
	unsigned int i = 0;

	(void)i;
	return (section.sh_size != 0
		&& section.sh_type != SHT_NOBITS
		&& section.sh_type != SHT_NULL
		&& section.sh_type != SHT_SYMTAB
		&& section.sh_flags != SHF_INFO_LINK
		&& (section.sh_type != SHT_STRTAB
			|| section.sh_flags == SHF_ALLOC));
}

int check_section32(Elf32_Shdr section, Elf32_Ehdr *elf)
{
	unsigned int i = 0;

	(void)i;
	return (section.sh_size != 0
	&& section.sh_type != SHT_NOBITS
	&& (elf->e_type != ET_REL || section.sh_type != SHT_REL)
	&& section.sh_type != SHT_NULL
	&& section.sh_type != SHT_SYMTAB
	&& section.sh_flags != SHF_INFO_LINK
	&& (section.sh_type != SHT_STRTAB
	|| section.sh_flags == SHF_ALLOC));
}
