/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex06
*/

#ifndef ITERATOR_H_
# define ITERATOR_H_

#include "object.h"

typedef struct s_Iterator Iterator;

typedef void (*incr_t)(Iterator* self);
typedef Object* (*getval_t)(Iterator* self);
typedef void (*setval_t)(Iterator* self, ...);

struct s_Iterator
{
	Class base;
	incr_t __incr__;
	getval_t __getval__;
	setval_t __setval__;
};

# define incr(it) (((Iterator*) it)->__incr__(it))
# define getval(it) (((Iterator*) it)->__getval__(it))
# define setval(it, ...) (((Iterator*) it)->__setval__(it, __VA_ARGS__))

#endif /* ITERATOR_H_ */
