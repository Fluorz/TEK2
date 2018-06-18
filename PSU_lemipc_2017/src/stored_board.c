/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        stored_board.c
*/

#include "../include/lemipc.h"

/*
Return une map contenant que des point '.'
*/

const char	*put_maps(void)
{
	char	*map;
	int	i = 0;
	int	x = 0;
	int	y = 0;

	map = malloc(sizeof(char) * LINES * ROWS + LINES + 1);
	while (x != LINES) {
		y = 0;
		while (y != ROWS) {
			map[i] = '.';
			y++;
			i++;
		}
		map[i] = '\n';
		x++;
		i++;
	}
	map[i] = '\0';
	return (map);
}
