/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        point.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "point.h"

static void Point_ctor(Object* self, va_list *args);
static void Point_dtor(Object* self);
static char const *Point_to_string(Object *self);

const char *POINT_TEMPLATE = "<%s (%d, %d)>";

typedef struct
{
	Class base;
	int x, y;
} PointClass;

static PointClass _desc = {
	{sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, NULL},
	0, 0
};

static void Point_ctor(Object* self, va_list *args)
{
	PointClass	*pc;

	pc = self;
	pc->x = va_arg(*args, int);
	pc->y = va_arg(*args, int);
	if (*args)
		pc->base.__str__ = &Point_to_string;
}

static void Point_dtor(Object* self)
{
	PointClass	*tmp;

	tmp = self;
	if (tmp) {
		memset(self, 0, sizeof(Class));
	}
}

static char const *Point_to_string(Object *self)
{
	char		*str;
	size_t		len;
	unsigned int 	max_const_chars = 26;
	PointClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + max_const_chars;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, POINT_TEMPLATE, pc->base.__name__, pc->x, pc->y);
	return (str);
}

Class *Point = (Class *)&_desc;
