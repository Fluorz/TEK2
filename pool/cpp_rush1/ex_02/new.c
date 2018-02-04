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
#include "point.h"
#include "vertex.h"

Object *new(Class *class, ...)
{
	Object	*obj;
	va_list	ap;

	if (!class)
		return (NULL);
	va_start(ap, class);
	obj = va_new(class, &ap);
	va_end(ap);
	return (obj);
}

Object *va_new(Class *class, va_list *ap)
{
	Object *obj = NULL;

	if (!class)
		return (obj);
	obj = malloc(class->__size__);
	if (!obj)
		raise("Malloc failed");
	memcpy(obj, class, class->__size__);
	if (class->__init__)
		class->__init__(obj, ap);
	return (obj);
}

void 	delete(Object *ptr)
{
	Class 	*tmp;

	tmp = ptr;
	if (tmp && tmp->__del__)
		tmp->__del__(ptr);
	free(tmp);
}
