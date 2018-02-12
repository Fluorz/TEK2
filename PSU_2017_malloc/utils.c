/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
**        free.c
*/

#include "malloc.h"

void fusion(t_block block)
{
	block->size += block->next->size + sizeof(struct s_block);
	block->next = block->next->next;
	if (block->next)
		block->next->prev = block;
}

void split_block(t_block block, size_t s)
{
	t_block new = (t_block)((char *) block + s);

	new->prev = block;
	new->next = block->next;
	new->size = block->size - s;
	new->free = 1;
	new->data = new + 1;
	if (block->next)
		block->next->prev = new;
	block->next = new;
	block->size = s - sizeof(struct s_block);
}

int add_heap(t_block *block, t_block *last, size_t s)
{
	t_block new_b = sbrk(s);

	if (new_b == (void *) -1)
		return (0);
	new_b->next = NULL;
	new_b->prev = *last;
	new_b->size = s - sizeof(struct s_block);
	new_b->data = new_b + 1;
	(*last)->next = new_b;
	*block = new_b;
	return (1);
}
