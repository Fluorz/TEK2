/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        print_source.c
*/

#include "../include/objdump.h"

static source32_t 	*init_source(info_t *info)
{
	source32_t	*new;

	new = malloc(sizeof(source32_t));
	if (new == NULL)
		exit (84);
	new->elf = (Elf32_Ehdr*)info->data;
	new->section_tab = (Elf32_Shdr*)((void*)new->elf + new->elf->e_shoff);
	new->section_string = new->section_tab[new->elf->e_shstrndx];
	new->string = (char*)((void*)new->elf + new->section_string.sh_offset);
	return (new);
}

static void 	loop(source32_t *source)
{
	Elf32_Shdr section;
	unsigned int	i = 1;

	while (i < source->elf->e_shnum)
	{
		section = source->section_tab[i];
		if (check_section32(section, source->elf))
		{
		print_content_line(source->string + section.sh_name);
		print_32(source, section);
		}
		i++;
	}
}

void 	print_source32(info_t *info)
{
	source32_t *source;

	source = init_source(info);
	loop(source);
}
