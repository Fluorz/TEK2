/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        flags.c
*/

#include "../include/objdump.h"

static flags_t init_flags(void)
{
	flags_t new;

	new.exec_p = false;
	new.has_reloc = false;
	new.has_syms = false;
	new.dynamic = false;
	new.d_paged = false;
	new.checked = false;
	new.total = 0;
	return (new);
}

static flags_t	other_flags_conditions(Elf32_Shdr *sections, Elf32_Ehdr *elf,
	flags_t new)
{
	if (sections->sh_type != SHT_SYMTAB || sections->sh_type != SHT_DYNAMIC)
	{
		new.has_syms = true;
		new.total += HAS_SYMS;
	}
	if (elf->e_phnum != 0)
	{
		new.d_paged = true;
		new.total += D_PAGED;
	}
	return (new);
}

static flags_t	get_flags(Elf32_Ehdr *elf)
{
	Elf32_Shdr* sections = (Elf32_Shdr*)((void*)elf + elf->e_shoff);
	flags_t new;

	new = init_flags();
	switch (elf->e_type) {
	case ET_EXEC :
		new.exec_p = true;
		new.total += ET_EXEC;
		break;
	case HAS_RELOC :
		new.has_reloc = true;
		new.total += HAS_RELOC;
		break;
	case ET_DYN :
		new.dynamic = true;
		new.total += DYNAMIC;
		break;
	}
	return (other_flags_conditions(sections, elf, new));
}

static bool 	put_coma(bool checked, char *string)
{
	if (checked == true)
		printf(", %s", string);
	else
		printf("%s", string);
	return (true);
}

void 	print_flags32(Elf32_Ehdr *elf)
{
	flags_t flags;

	flags = get_flags(elf);
	printf(", flags 0x%08x:\n", flags.total);
	if (flags.exec_p == true)
		flags.checked = put_coma(flags.checked, "EXEC_P");
	if (flags.has_reloc == true)
		flags.checked = put_coma(flags.checked, "HAS_RELOC");
	if (flags.has_syms == true)
		flags.checked = put_coma(flags.checked, "HAS_SYMS");
	if (flags.dynamic == true)
		flags.checked = put_coma(flags.checked, "DYNAMIC");
	if (flags.d_paged == true)
		flags.checked = put_coma(flags.checked, "D_PAGED");
}
