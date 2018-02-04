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
#include "new.h"

static void Point_ctor(Object* self, va_list *args);
static void Point_dtor(Object* self);
static char const *Point_to_string(Object *self);
static Object *Point_add(const Object* self, const Object* other);
static Object *Point_sub(const Object* self, const Object* other);

const char *POINT_TEMPLATE = "<%s (%d, %d)>";

typedef struct
{
	Class base;
	int x, y;
} PointClass;

static PointClass _desc = {
	{sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, NULL,
	&Point_add, &Point_sub},
	0, 0
};

static void Point_ctor(Object* self, va_list *args)
{
	PointClass	*pc;

	pc = self;
	pc->x = va_arg(*args, int);
	pc->y = va_arg(*args, int);
	if (args)
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
	PointClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + 26;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, POINT_TEMPLATE, pc->base.__name__, pc->x, pc->y);
	return (str);
}

static Object *Point_add(const Object *self, const Object *other)
{
	const PointClass *self_point = self;
	const PointClass *other_point = other;

	return (new(Point, self_point->x + other_point->x,
		self_point->y + other_point->y));
}

static Object *Point_sub(const Object *self, const Object *other)
{
	const PointClass *self_point = self;
	const PointClass *other_point = other;

	return (new(Point, self_point->x - other_point->x,
		self_point->y - other_point->y));
}

Class *Point = (Class *)&_desc;
