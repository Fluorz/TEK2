/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
**        malloc.c
*/

#include "malloc.h"

static void *first_malloc()
{
	static t_block b = NULL;

	if (!b) {
		b = sbrk(align(sizeof(struct s_block)));
		if (b == (void*) -1)
			return (NULL);
		b->next = NULL;
		b->prev = NULL;
		b->size = 0;
		b->free = 0;
		b->data = NULL;
	}
	return (b);
}

t_block find_block(t_block *last, size_t s)
{
	t_block c = first_malloc();

	while (c && (!c->free || c->size < s)) {
		*last = c;
		c = c->next;
	}
	return (c);
}

void *malloc(size_t size)
{
	size_t s = align(size + sizeof(struct s_block));
	t_block last = NULL;
	t_block block = find_block(&last, size);

	if (!size)
		return (NULL);
	if (!block) {
		add_heap(&block, &last, s);
	} else if (s + sizeof(size_t) < block->size)
		split_block(block, s);
	block->free = 0;
	return (block->data);
}

void free(void *ptr)
{
	t_block block;

	if (!ptr || ptr < first_malloc() || ptr > sbrk(0))
		return;
	block = (t_block) ptr - 1;
	if (block->data != ptr)
		return;
	block->free = 1;
	if (block->next && block->next->free)
		fusion(block);
	if (block->prev->free)
		fusion(block = block->prev);
	if (!block->next) {
		block->prev->next = NULL;
		sbrk(- block->size - sizeof(struct s_block));
	}
}

void *realloc(void *ptr, size_t size)
{
	void *nptr = malloc(size);
	char *dst = nptr, *src = ptr;
	t_block block;
	size_t s;

	if (nptr && ptr && ptr >= first_malloc() && ptr <= sbrk(0)) {
		block = (t_block) ptr - 1;
		if (block->data == ptr) {
			s = block->size > size ? size : block->size;
			for (size_t i = 0; i < s; *dst = *src, ++i) {
				++src;
				++dst;
			}
			free(ptr);
		}
	}
	return (nptr);
}
