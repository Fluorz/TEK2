/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        vertex.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "point.h"
#include "new.h"
#include "vertex.h"

static void Vertex_ctor(Object* self, va_list *args);
static void Vertex_dtor(Object* self);
static char const *Vertex_to_string(Object *self);
static Object *Vertex_add(const Object* self, const Object* other);
static Object *Vertex_sub(const Object* self, const Object* other);

const char *VERTEX_TEMPLATE = "<%s (%d, %d, %d)>";

typedef struct
{
	Class base;
	int x, y, z;
} VertexClass;

static VertexClass _desc = {
	{sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, NULL,
	&Vertex_add, &Vertex_sub},
	0, 0, 0
};

static void Vertex_ctor(Object* self, va_list *args)
{
	VertexClass	*pc;

	pc = self;
	pc->x = va_arg(*args, int);
	pc->y = va_arg(*args, int);
	pc->z = va_arg(*args, int);
	if (args)
		pc->base.__str__ = &Vertex_to_string;
}

static void Vertex_dtor(Object* self)
{
	VertexClass	*tmp;

	tmp = self;
	if (tmp) {
		memset(self, 0, sizeof(Class));
	}
}

static char const *Vertex_to_string(Object *self)
{
	char		*str;
	size_t		len;
	VertexClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + 27;
	str = malloc(sizeof(char) * len);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, VERTEX_TEMPLATE, pc->base.__name__, pc->x, pc->y,
		pc->z);
	return (str);
}

static Object *Vertex_add(const Object *self, const Object *other)
{
	const VertexClass *self_point = self;
	const VertexClass *other_point = other;

	return (new(Vertex, self_point->x + other_point->x,
		self_point->y + other_point->y));
}

static Object *Vertex_sub(const Object *self, const Object *other)
{
	const VertexClass *self_point = self;
	const VertexClass *other_point = other;

	return (new(Vertex, self_point->x - other_point->x,
		self_point->y - other_point->y,
		self_point->z - other_point->z));
}

Class *Vertex = (Class *)&_desc;
