/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        elf_64.c
*/

#include "../include/nm.h"
#include "../include/list.h"

void set_sym_64(s64_t *elf)
{
	for (int i = 0; i < elf->elf->e_shnum; i++) {
		if (elf->shdr[i].sh_size) {
			if (!strcmp(&elf->strtab[elf->shdr[i].sh_name],
				".symtab"))
			elf->symsection = (Elf64_Shdr*)&elf->shdr[i];
			if (!strcmp(&elf->strtab[elf->shdr[i].sh_name],
				".strtab"))
			elf->strsymsection = (Elf64_Shdr*)&elf->shdr[i];
		}
	}
}

s64_t *init_elf_64(void *data)
{
	s64_t *new;

	new = malloc(sizeof(s64_t));
	if (new == NULL)
		exit (84);
	new->elf = (Elf64_Ehdr*)data;
	new->shdr = (Elf64_Shdr*)(data + new->elf->e_shoff);
	new->strtab = (char*)(data + new->shdr[new->elf->e_shstrndx].sh_offset);
	new->strsymsection = NULL;
	new->symsection = NULL;
	set_sym_64(new);
	new->symtab = (Elf64_Sym*)((char*)data + new->symsection->sh_offset);
	new->strsymtab = (char*)((char*)data + new->strsymsection->sh_offset);
	return (new);
}

void check_header64(info_t *info)
{
	Elf64_Ehdr *elf;

	elf = info->data;
	if (elf->e_ident[EI_MAG0] != ELFMAG0 ||
		elf->e_ident[EI_MAG1] != ELFMAG1 ||
		elf->e_ident[EI_MAG2] != ELFMAG2 ||
		elf->e_ident[EI_MAG3] != ELFMAG3 ||
		(elf->e_type != ET_REL &&
			elf->e_type !=  ET_EXEC &&
			elf->e_type != ET_DYN)) {
		fprintf(stderr, "nm: %s: File format not recognized\n",
			info->file);
		exit (84);
	}
	if (elf->e_phoff > info->size ||
	elf->e_shoff > info->size) {
	fprintf(stderr, "nm: %s: File truncated\n",
		info->file);
	exit (84);
	}
}

Elf64_Sym **get_symtab_cpy(Elf64_Sym *symtab, unsigned int size)
{
	Elf64_Sym	**new;

	new = malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		exit (84);
	for (unsigned int i = 0; i < size; ++i)
		new[i] = &symtab[i];
	return (new);
}

void elf64_format(info_t *info)
{
	s64_t *elf;
	list_t list;

	check_header64(info);
	elf = init_elf_64(info->data);
	list = get_list(elf);
	sort_list(&list);
	else_sort_list(&list);
	list_dump(list);
}
