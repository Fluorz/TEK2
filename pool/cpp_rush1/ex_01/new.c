/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        new.c
*/

#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "raise.h"

void 	*new(Class *class)
{
	Object *obj;

	if (!class)
		raise("Class undefined");
	obj = malloc(class->__size__);
	if (!obj)
		raise("Malloc failed");
	memcpy(obj, class, class->__size__);
	if (class->__init__)
		class->__init__(obj);
	return (obj);
}

void 	delete(Object *ptr)
{
	Class 	*tmp;

	if (!ptr)
		raise("Pointer null");
	tmp = ptr;
	if (tmp->__del__)
		tmp->__del__(ptr);
	free(tmp);
}
