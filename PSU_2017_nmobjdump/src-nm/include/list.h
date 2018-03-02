/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        list.h
*/

#ifndef _LIST_
# define _LIST_

#include "nm.h"

# define LOWER(x)	(x >= 'A' && x <= 'Z' ? x + 0x20 : x)

typedef struct info_list_s
{
	char *name;
	uint32_t first;
	uint32_t second;
	char type;
}	info_list_t;

typedef struct node_s
{
	char *name;
	char *epur;
	uint32_t first;
	uint32_t second;
	char type;
	struct node_s *next;
	struct node_s *prev;
}	node_t;

typedef node_t *list_t;

void list_dump(list_t list);
void list_add_elem_at_front(list_t *front_ptr, info_list_t info);
list_t add_to_list(list_t list, s64_t *elf, int i);
list_t get_list(s64_t *elf);
void sort_list(list_t*);
void else_sort_list(list_t *list);
char *get_name(char *name);
list_t get_list32(s32_t *elf);
list_t add_to_list32(list_t list, s32_t *elf, int i);
void list_dump32(list_t list);

#endif
