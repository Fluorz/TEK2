/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        sort_list.c
*/

#include "../include/list.h"

unsigned int list_get_size(list_t list)
{
	unsigned int	i = 0;
	list_t	tmp;

	tmp = list;
	while (list->next != tmp) {
		i++;
		list = list->next;
	}
	return (i);
}

char *get_name(char *name)
{
	char *tmp_name;

	tmp_name = malloc(sizeof(char) * strlen(name) + 1);
	tmp_name = strcpy(tmp_name, name);
	return (tmp_name);
}

static void swap_elem(list_t *list)
{
	char *tmp_name; char *tmp_epur;
	uint32_t tmp_first; uint32_t tmp_second;
	char tmp_type;

	tmp_name = get_name((*list)->name);
	tmp_epur = get_name((*list)->epur);
	tmp_first = (*list)->first;
	tmp_second = (*list)->second;
	tmp_type = (*list)->type;
	(*list)->name = get_name((*list)->next->name);
	(*list)->epur = get_name((*list)->next->epur);
	(*list)->first = (*list)->next->first;
	(*list)->second = (*list)->next->second;
	(*list)->type = (*list)->next->type;
	(*list)->next->name = get_name(tmp_name);
	(*list)->next->epur = get_name(tmp_epur);
	(*list)->next->first = tmp_first;
	(*list)->next->second = tmp_second;
	(*list)->next->type = tmp_type;
}

void sort_list(list_t *list)
{
	int didswap = 1; int unsigned i = 0;
	int unsigned limit = list_get_size(*list) + 1;

	while (didswap) {
		i = 0;
		didswap = 0;
		for (i = 0; i < limit; i++) {
	if (i < limit - 1 && strcmp((*list)->epur, (*list)->next->epur) == 0
	&& strcmp((*list)->name, (*list)->next->name) > 0
	&& (*list)->next->type != 'T') {
				swap_elem(list);
				didswap = 1;
			}
else if (i < limit - 1 && strcmp((*list)->epur, (*list)->next->epur) > 0) {
				swap_elem(list);
				didswap = 1;
			}
			(*list) = (*list)->next;
		}
	}
}

void else_sort_list(list_t *list)
{
	int didswap = 1;
	int unsigned i = 0;
	int unsigned limit = list_get_size(*list) + 1;

	didswap = 1;
	while (didswap) {
		i = 0;
		didswap = 0;
		for (i = 0; i < limit; i++) {
			int j = 0;
			while ((*list)->epur[j] == (*list)->next->epur[j])
			j++;
if (i < limit - 1 && ((*list)->epur[j] == '_' || (*list)->epur[j] == '@')) {
				swap_elem(list);
				didswap = 1;
			}
			(*list) = (*list)->next;
		}
	}
}
