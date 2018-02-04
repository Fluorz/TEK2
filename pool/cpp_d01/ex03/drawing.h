/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        drawing.h
*/

#ifndef __DRAWING_H__
#define __DRAWING_H__

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_point
{
	unsigned int x;
	unsigned int y;
}		point_t;

void	draw_square(uint32_t **img, point_t * origin, size_t size,
	uint32_t color);

#endif
