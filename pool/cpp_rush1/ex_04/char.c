/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
**        char.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "char.h"
#include "new.h"
#include "bool.h"

static void Char_ctor(Object* self, va_list *args);
static void Char_dtor(Object* self);
static char const *Char_to_string(Object *self);
static Object *Char_add(const Object* self, const Object* other);
static Object *Char_sub(const Object* self, const Object* other);
static Object *Char_mul(const Object* self, const Object* other);
static Object *Char_div(const Object* self, const Object* other);
static bool Char_eq(const Object* self, const Object* other);
static bool Char_gt(const Object* self, const Object* other);
static bool Char_lt(const Object* self, const Object* other);

const char *CHAR_TEMPLATE = "<%s (%c)>";

typedef struct
{
	Class base;
	char _char;
} CharClass;

static CharClass _desc = {
	{sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, NULL,
		&Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq,
	&Char_gt, &Char_lt},
	0
};

static void Char_ctor(Object* self, va_list *args)
{
	CharClass	*pc;

	pc = self;
	pc->_char = va_arg(*args, int);
	if (args)
		pc->base.__str__ = &Char_to_string;
}

static void Char_dtor(Object* self)
{
	CharClass	*tmp;

	tmp = self;
	if (tmp) {
		memset(self, 0, sizeof(Class));
	}
}

static char const *Char_to_string(Object *self)
{
	char		*str;
	size_t		len;
	CharClass	*pc = self;

	if (!pc)
		return (NULL);
	len = strlen(pc->base.__name__) + 26;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		raise("Malloc failed");
	memset(str, 0, len);
	snprintf(str, len, CHAR_TEMPLATE, pc->base.__name__, pc->_char);
	return (str);
}

static Object *Char_add(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	return (new(Char, self_char->_char + other_char->_char));
}

static Object *Char_sub(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	return (new(Char, self_char->_char - other_char->_char));
}

static Object *Char_mul(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	return (new(Char, self_char->_char * other_char->_char));
}

static Object *Char_div(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	return (new(Char, self_char->_char / other_char->_char));
}

static bool Char_eq(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	if (self_char->_char == other_char->_char)
		return (true);
	return (false);
}

static bool Char_gt(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	if (self_char->_char > other_char->_char)
		return (true);
	return (false);
}

static bool Char_lt(const Object *self, const Object *other)
{
	const CharClass *self_char = self;
	const CharClass *other_char = other;

	if (self_char->_char < other_char->_char)
		return (true);
	return (false);
}

Class *Char = (Class *)&_desc;
