/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
**        malloc.h
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stddef.h>
#include <pthread.h>

#define alignBit(x) (((x) + 3) & ~3)
#define align(x) (((x) - 1) / getpagesize() * getpagesize() + getpagesize())

struct s_block
{
	struct s_block *next, *prev;
	size_t        size;
	int           free;
	void         *data;
};

typedef struct s_block *t_block;

t_block find_block(t_block *, size_t s);
void split_block(t_block block, size_t s);
void fusion(t_block block);
int add_heap(t_block *block, t_block *last, size_t s);

#endif
