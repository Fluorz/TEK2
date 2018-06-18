/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        check_neighboor.c
*/

#include "../include/lemipc.h"

/*
Fonctions regardant les voisins
*/

static int	top_bottom(char *map, int i, int result, char buff[9])
{
	if (i / ROWS < LINES && map[i + ROWS + 1] != '.'
	&& map[i + (ROWS + 1)] != '\n'
	&& map[i + ROWS + 1] != map[i]) {
		buff[result] = map[i + ROWS + 1];
		result++;
	}
	if (i > ROWS && map[i - (ROWS + 1)] != '.'
	&& map[i - (ROWS + 1)] != '\n'
	&& map[i - (ROWS + 1)] != map[i]) {
		buff[result] = map[i - (ROWS + 1)];
		result++;
	}
	return (result);
}

static int	corner_top(char *map, int i, int result, char buff[9])
{
	if (i / ROWS < LINES && map[i + ROWS] != '.'
	&& map[i + ROWS] != '\n' && map[i + ROWS] != map[i]) {
		buff[result] = map[i + ROWS];
		result++;
	}
	if (i / ROWS < LINES && map[i + ROWS + 2] != '.'
	&& map[i + ROWS + 2] != '\n' && map[i + ROWS + 2] != map[i]) {
		buff[result] = map[i + ROWS + 2];
		result++;
	}
	return (result);
}

static int	corner_bottom(char *map, int i, int result, char buff[9])
{
	if (i > ROWS && map[i - (ROWS + 2)] != '.'
	&& map[i - (ROWS + 2)] != '\n' && map[i - (ROWS + 2)] != map[i]) {
		buff[result] = map[i - (ROWS + 2)];
		result++;
	}
	if (i > ROWS && map[i - (ROWS)] != '.' && map[i - (ROWS)] != '\n'
	&& map[i - ROWS] != map[i]) {
		buff[result] = map[i - ROWS];
		result++;
	}
	return (result);
}

static int	right_left(char *map, int i, int result, char buff[9])
{
	if (i != 0 && map[i - 1] != '.' && map[i - 1] != '\n'
	&& map[i - 1] != map[i])
	{
		buff[result] = map[i - 1];
		result++;
	}
	if (map[i + 1] != '\0' && map[i + 1] != '.'
	&& map[i + 1] != '\n' && map[i + 1] != map[i])
	{
		buff[result] = map[i + 1];
		result++;
	}
	return (result);
}

/*
Regarde successivement les positions voisines
pour detecter si le joueur est en echec
*/

int	check_position(char *map, int i)
{
	char	buff[9] = "LLLLLLLLL";
	int result = 0;

	result = top_bottom(map, i, result, buff);
	result = right_left(map, i, result, buff);
	result = corner_bottom(map, i, result, buff);
	result = corner_top(map, i, result, buff);
	return (check_same_team(buff));
}
