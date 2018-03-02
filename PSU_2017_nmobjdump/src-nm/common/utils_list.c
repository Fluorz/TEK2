/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        utils_list.c
*/

#include "../include/list.h"
#include "../include/nm.h"

void list_dump(list_t list)
{
	list_t tmp;

	tmp = list;
	while (list->next != tmp) {
		if (list->type != 'U' && list->type != 'w')
			printf("%08x%08x ", list->first, list->second);
		else
			printf("%17c", ' ');
		printf("%c ", list->type);
		printf("%s\n", list->name);
		list = list->next;
	}
	if (list->type != 'U' && list->type != 'w')
		printf("%08x%08x ", list->first, list->second);
	else
		printf("%17c", ' ');
	printf("%c ", list->type);
	printf("%s\n", list->name);
}

void list_dump32(list_t list)
{
	list_t tmp;

	tmp = list;
	while (list->next != tmp) {
		if (list->type != 'U' && list->type != 'w')
			printf("%08x ", list->first);
		else
			printf("%9c", ' ');
		printf("%c ", list->type);
		printf("%s\n", list->name);
		list = list->next;
	}
	if (list->type != 'U' && list->type != 'w')
		printf("%08x ", list->first);
	else
		printf("%9c", ' ');
	printf("%c ", list->type);
	printf("%s\n", list->name);
}

list_t get_list32(s32_t *elf)
{
	unsigned int i = 0;
	unsigned int	size;
	list_t list = NULL;

	size = elf->symsection->sh_size / sizeof(*elf->symtab);
	elf->symtab_cpy = get_symtab_cpy32(elf->symtab, size);
	while (++i < size)
	{
		list = add_to_list32(list, elf, i);
	}
	return (list);
}

list_t get_list(s64_t *elf)
{
	unsigned int i = 0;
	unsigned int	size;
	list_t list = NULL;

	size = elf->symsection->sh_size / sizeof(*elf->symtab);
	elf->symtab_cpy = get_symtab_cpy(elf->symtab, size);
	while (++i < size)
	{
		list = add_to_list(list, elf, i);
	}
	return (list);
}
