/*
** EPITECH PROJECT, 2018
** pool
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02a/ex00
** simple_list.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "simple_list.h"

unsigned int list_get_size(list_t list)
{
	unsigned int	i = 0;

	while (list->next != NULL) {
		i++;
		list = list->next;
	}
	return (i);
}

bool_t list_is_empty(list_t list)
{
	if (list == NULL && list->next == NULL)
		return (FALSE);
	else
		return (TRUE);
}

void list_dump(list_t list)
{
	while (list != NULL) {
		printf("%f\n", list->value);
		list = list->next;
	}
}

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
	node_t	*new_elem;

	new_elem = malloc(sizeof(list_t));
	if (new_elem == NULL) {
		return (FALSE);
	}
	new_elem->value = elem;
	new_elem->next = *front_ptr;
	*front_ptr = new_elem;
	return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
	node_t	*list_tmp;
	node_t	*new_elem;

	if (*front_ptr == NULL) {
	return (list_add_elem_at_front(front_ptr, elem));
	}
	list_tmp = *front_ptr;
	new_elem = malloc(sizeof(node_t));
	if (new_elem == NULL)
		return (FALSE);
	while (list_tmp && list_tmp->next != NULL) {
		list_tmp = list_tmp->next;
	}
	new_elem->value = elem;
	new_elem->next = NULL;
	list_tmp->next = new_elem;
	return (TRUE);
}

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, unsigned int
position)
{
	list_t list_tmp;
	node_t *new_elem;

	list_tmp = *front_ptr;
	new_elem = malloc(sizeof(node_t));
	new_elem->value = elem;
	if (new_elem == NULL) return (FALSE);
	if (position == 0) return (list_add_elem_at_front(front_ptr, elem));
	if (!*front_ptr) return (FALSE) ;
	while (--position) {
		list_tmp = list_tmp->next;
	}
	new_elem->next = list_tmp->next;
	list_tmp->next = new_elem;
	return (TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr)
{
	if (!(*front_ptr))
		return (FALSE);
	*front_ptr = (*front_ptr)->next;
	return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
	list_t list;
	list_t previous;

	list = *front_ptr;
	previous = NULL;
	if (list == NULL)
		return (FALSE);
	while (list->next) {
		previous = list;
		list = list->next;
	}
	if (previous) {
		previous->next = NULL;
	}
	return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
	list_t	list;
	list_t	previous;

	position++;
	list = *front_ptr;
	previous = NULL;
	if (list == NULL) return (FALSE);
	while (--position && list->next) {
		previous = list;
		list = list->next;
	}
	if (previous && list->next->next) {
		previous->next = list->next;
	}
	return (TRUE);
}

double list_get_elem_at_front(list_t list)
{
	if (list) {
		return (list->value);
	}
	return (0);
}

double list_get_elem_at_back(list_t list)
{
	list_t	tmp;

	tmp = list;
	while (tmp->next){
		tmp = tmp->next;
	}
	if (tmp) {
		return (tmp->value);
	}
	return (0);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
	list_t	tmp;

	tmp = list;
	position++;
	while (--position && tmp->next){
		tmp = tmp->next;
	}
	if (tmp) {
		return (tmp->value);
	}
	return (0);
}

node_t * list_get_first_node_with_value(list_t list, double value)
{
	node_t	*tmp;

	tmp = list;
	while (tmp->next) {
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
