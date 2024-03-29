/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        get_flag.c
*/

#include "../include/nm.h"
#include "../include/list.h"

static flags_t		localflags[] = {
	{ STT_NOTYPE, SHT_PROGBITS, 3, 'd' },
	{ STT_NOTYPE, SHT_PROGBITS, 6, 't' },
	{ STT_OBJECT, SHT_DYNAMIC, 3, 'd' },
	{ STT_OBJECT, SHT_FINI_ARRAY, 3, 't' },
	{ STT_OBJECT, SHT_INIT_ARRAY, 3, 't' },
	{ STT_OBJECT, SHT_PROGBITS, 3, 'd' },
	{ STT_FUNC, SHT_PROGBITS, 6, 't' },
	{ STT_TLS, SHT_PROGBITS, 1027, 'd' }
};

static type_t		types[] = {
	{'B', SHT_NOBITS, SHF_ALLOC | SHF_WRITE},
	{'R', SHT_PROGBITS, SHF_ALLOC},
	{'D', SHT_PROGBITS, SHF_ALLOC | SHF_WRITE},
	{'U', SHT_NULL, 0},
	{'T', SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR},
	{'R', SHT_PROGBITS, 0}
};

static char	symbol32(s32_t *elf, Elf32_Sym *symtab, Elf32_Shdr *shdr)
{
	char type = '?';

	if ((symtab->st_shndx != SHN_ABS && symtab->st_shndx != SHN_COMMON) &&
	ELF32_ST_BIND(symtab->st_info) == STB_LOCAL) {
		for (unsigned int i = 0; i < 8; i++) {
		if (shdr[symtab->st_shndx].sh_type == localflags[i].type
		&& shdr[symtab->st_shndx].sh_flags == localflags[i].flags)
		return (localflags[i].ch);
			}
		}
	for (unsigned int i = 0; i < 6; i++) {
		if (elf->shdr[symtab->st_shndx].sh_type == types[i].type
		&& elf->shdr[symtab->st_shndx].sh_flags == types[i].flags)
			type = types[i].ch;
	}
	type = ELF32_ST_BIND(symtab->st_info) == STB_LOCAL ? LOWER(type) : type;
	type = ELF32_ST_BIND(symtab->st_info) == STB_WEAK ? 'w' : type;
	type = type == '?' ? 't' : type;
	return (type);
}

static char	easy_one32(Elf32_Sym *sym, Elf32_Addr value)
{
	char type = 0;

	if (ELF32_ST_BIND(sym->st_info) == STB_WEAK) {
		if (!value)
		return (ELF32_ST_TYPE(sym->st_info) == STT_OBJECT ? 'v' : 'w');
		return (ELF32_ST_TYPE(sym->st_info) == STT_OBJECT ? 'V' : 'W');
	}
	type = sym->st_shndx == SHN_UNDEF ? 'U' : type;
	type = sym->st_shndx == SHN_COMMON ? 'C' : type;
	type = sym->st_shndx == SHN_ABS ? 'A' : type;
	return (type);
}

static char get_flag32(s32_t *elf, Elf32_Sym *sym, Elf32_Addr value)
{
	char type;

	type = easy_one32(sym, value);
	if (type != 0)
		return (type);
	if ((type = symbol32(elf, sym, elf->shdr)) != '?')
		return (type);
	return (type);
}

list_t add_to_list32(list_t list, s32_t *elf, int i)
{
	info_list_t info;
	char type;

	if (elf->symtab_cpy[i]->st_name != 0 &&
		elf->symtab_cpy[i]->st_name != 1 &&
		elf->symtab_cpy[i]->st_info != 4) {
	type = get_flag32(elf, elf->symtab_cpy[i], elf->symtab[i].st_value);
		if (type != 'U' && type != 'w') {
		info.first = elf->symtab_cpy[i]->st_value;
		info.second = 0;
		}
		info.type = type;
	info.name = get_name(&elf->strsymtab[elf->symtab_cpy[i]->st_name]);
		list_add_elem_at_front(&list, info);
	}
	return (list);
}
