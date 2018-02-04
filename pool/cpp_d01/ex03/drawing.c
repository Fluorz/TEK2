/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        drawing.c
*/

#include "drawing.h"

void	draw_square(uint32_t **img, point_t *origin,
	size_t size, uint32_t color)
{
	size_t	y = 0;
	size_t	x = 0;

	y = origin->y;
	while (y < size) {
		x = origin->x;
		while (x < size) {
			img[y][x] = color;
			x = x + 1;
		}
		y = y + 1;
	}
}
