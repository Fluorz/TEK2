/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex05
*/

#ifndef NEW_H_
#define NEW_H_

#include <stdarg.h>
#include "object.h"

Object* new(Class * class, ...);
Object* va_new(Class* class, va_list* ap);
void delete(Object * ptr);

#endif /* NEW_H_ */
