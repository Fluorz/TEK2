/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        float.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "float.h"
#include "new.h"
#include "bool.h"

static void Float_ctor(Object* self, va_list *args);
static void Float_dtor(Object* self);
static char const *Float_to_string(Object *self);
static Object *Float_add(const Object* self, const Object* other);
static Object *Float_sub(const Object* self, const Object* other);
static Object *Float_mul(const Object* self, const Object* other);
static Object *Float_div(const Object* self, const Object* other);
static bool Float_eq(const Object* self, const Object* other);
static bool Float_gt(const Object* self, const Object* other);
static bool Float_lt(const Object* self, const Object* other);

const char *FLOAT_TEMPLATE = "<%s (%f)>";

typedef struct
{
	Class base;
	float _float;
} FloatClass;

static FloatClass _desc = {
	{sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, NULL,
		&Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq,
		&Float_gt, &Float_lt},
	0
};

static void Float_ctor(Object* self, va_list *args)
{
	FloatClass	*pc;

	pc = self;
	pc->_float = va_arg(*args, double);
	if (args)
		pc->base.__str__ = &Float_to_string;
}

static void Float_dtor(Object* self)
{
	FloatClass	*tmp;

	tmp = self;
	if (tmp) {
		memset(self, 0, sizeof(Class));
	}
}

static char const *Float_to_string(Object *self)
{
	char		*str;
	size_t		len;
	FloatClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + 26;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, FLOAT_TEMPLATE, pc->base.__name__, pc->_float);
	return (str);
}

static Object *Float_add(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	return (new(Float, self_float->_float + other_float->_float));
}

static Object *Float_sub(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	return (new(Float, self_float->_float - other_float->_float));
}

static Object *Float_mul(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	return (new(Float, self_float->_float * other_float->_float));
}

static Object *Float_div(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	return (new(Float, self_float->_float / other_float->_float));
}

static bool Float_eq(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	if (self_float->_float == other_float->_float)
		return (true);
	return (false);
}

static bool Float_gt(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	if (self_float->_float > other_float->_float)
		return (true);
	return (false);
}

static bool Float_lt(const Object *self, const Object *other)
{
	const FloatClass *self_float = self;
	const FloatClass *other_float = other;

	if (self_float->_float < other_float->_float)
		return (true);
	return (false);
}

Class *Float = (Class *)&_desc;
