/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        int.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "int.h"
#include "new.h"
#include "bool.h"

static void Int_ctor(Object* self, va_list *args);
static void Int_dtor(Object* self);
static char const *Int_to_string(Object *self);
static Object *Int_add(const Object* self, const Object* other);
static Object *Int_sub(const Object* self, const Object* other);
static Object *Int_mul(const Object* self, const Object* other);
static Object *Int_div(const Object* self, const Object* other);
static bool Int_eq(const Object* self, const Object* other);
static bool Int_gt(const Object* self, const Object* other);
static bool Int_lt(const Object* self, const Object* other);

const char *INT_TEMPLATE = "<%s (%d)>";

typedef struct
{
	Class base;
	int _int;
} IntClass;

static IntClass _desc = {
	{sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, NULL,
	&Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq,
		&Int_gt, &Int_lt},
	0
};

static void Int_ctor(Object* self, va_list *args)
{
	IntClass	*pc;

	pc = self;
	pc->_int = va_arg(*args, int);
	if (args)
		pc->base.__str__ = &Int_to_string;
}

static void Int_dtor(Object* self)
{
	IntClass	*tmp;

	tmp = self;
	if (tmp) {
		memset(self, 0, sizeof(Class));
	}
}

static char const *Int_to_string(Object *self)
{
	char		*str;
	size_t		len;
	IntClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + 26;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, INT_TEMPLATE, pc->base.__name__, pc->_int);
	return (str);
}

static Object *Int_add(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	return (new(Int, self_int->_int + other_int->_int));
}

static Object *Int_sub(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	return (new(Int, self_int->_int - other_int->_int));
}

static Object *Int_mul(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	return (new(Int, self_int->_int * other_int->_int));
}

static Object *Int_div(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	return (new(Int, self_int->_int / other_int->_int));
}

static bool Int_eq(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	if (self_int->_int == other_int->_int)
		return (true);
	return (false);
}

static bool Int_gt(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	if (self_int->_int > other_int->_int)
		return (true);
	return (false);
}

static bool Int_lt(const Object *self, const Object *other)
{
	const IntClass *self_int = self;
	const IntClass *other_int = other;

	if (self_int->_int < other_int->_int)
		return (true);
	return (false);
}

Class *Int = (Class *)&_desc;
