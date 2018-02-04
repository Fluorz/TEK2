/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex01
*/

#ifndef CLASS_H_
#define CLASS_H_

#include <sys/types.h>

typedef void Object;

typedef struct {
	const size_t __size__;
	const char* __name__;
	void (*__init__)(Object* self);
	void (*__del__)(Object* self);
} Class;

#endif /* CLASS_H_ */
