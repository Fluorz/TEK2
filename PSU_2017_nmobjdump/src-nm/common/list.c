/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        list.c
*/

#include "../include/list.h"
#include "../include/nm.h"

static char *else_epur(char *str, char *string)
{
	int i = 0;
	int j = 0;
	char *new;

	new = malloc(sizeof(char) * strlen(string) + 10);
	while (str[i] == '_' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j + 1] = '\0';
	return (new);
}

char *epur(char *string)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * strlen(string) + 10);
	while (string[i])
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
			str[i] = string[i] + 32;
		else
			str[i] = string[i];
		i++;
	}
	str[i + 1] = '\0';
	return (else_epur(str, string));
}

static void else_list_add_elem_at_front(list_t *front_ptr, info_list_t info)
{
	*front_ptr = malloc(sizeof(node_t));
	(*front_ptr)->name = malloc(sizeof(char) * strlen(info.name) + 1);
	(*front_ptr)->name = strcpy((*front_ptr)->name, info.name);
	(*front_ptr)->epur = epur((*front_ptr)->name);
	(*front_ptr)->first = info.first;
	(*front_ptr)->second = info.second;
	(*front_ptr)->type = info.type;
	(*front_ptr)->next = *front_ptr;
	(*front_ptr)->prev = *front_ptr;
	return;
}

void list_add_elem_at_front(list_t *front_ptr, info_list_t info)
{
	node_t	*new_elem;

	new_elem = malloc(sizeof(node_t));
	if (new_elem == NULL)
		exit (84);
	if (*front_ptr == NULL)
		return (else_list_add_elem_at_front(front_ptr, info));
	new_elem = (*front_ptr)->prev;
	new_elem->next = NULL;
	new_elem->next = malloc(sizeof(node_t));
	if (new_elem->next == NULL)
		exit (84);
	new_elem->next->name = get_name(info.name);
	new_elem->next->epur = epur(new_elem->next->name);
	new_elem->next->first = info.first;
	new_elem->next->second = info.second;
	new_elem->next->type = info.type;
	new_elem->next->next = *front_ptr;
	new_elem->next->prev = new_elem;
	(*front_ptr)->prev = new_elem->next;
}
