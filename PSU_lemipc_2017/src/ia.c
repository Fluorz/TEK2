/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        ia.c
*/

#include "../include/lemipc.h"

/*
Random pour la premiere position
*/

int	pos_first(lemipc_t *lemipc, int *first)
{
	char	*map;
	bool	ok = false;
	int	new = 0;

	*first = 1;
	map = get_map(lemipc);
	while (ok != true)
	{
		new = rand() % LINES * ROWS;
		if (map[new] == '.')
			ok = true;
	}
	return (new);
}

/*
Regarde l'ennemi le plus proche
return une valeur positif pour les joueurs en dessous
retrun une valeur negatif pour les joeurs au dessus
*/

int	get_near_one(lemipc_t *lemipc)
{
	int	neg = lemipc->current_pos;
	int	pos = lemipc->current_pos;
	char	*map = get_map(lemipc);

	while (1) {
		if (neg > 0 && map[neg] != '\n' && map[neg] != '.'
		&& map[neg] != map[lemipc->current_pos])
			return (neg);
		if (pos < (int)strlen(map) && map[pos] != '\n'
		&& map[pos] != '.' && map[pos] != map[lemipc->current_pos])
			return (pos);
		neg = (neg > 0) ? neg - 1 : -1;
		if (neg == -1)
			return (lemipc->current_pos + 1);
		pos = (pos < (int)strlen(map)) ? pos + 1 : -1;
		if (pos == -1)
			return (lemipc->current_pos - 1);
	}
	return (1);
}

/*
Regarde les positions possible: en haut et a gauche
*/

int	pos_top_left(lemipc_t *lemipc)
{
	int	test = 0;
	char	*map;

	map = get_map(lemipc);
	test = lemipc->current_pos - 1;
	if (map[test] == '.')
		return (test);
	test = lemipc->current_pos - (ROWS + 1);
	if (map[test] == '.')
		return (test);
	return (pos_bottom_right(lemipc));
}

/*
Regarde les positions possible: en bas et a droite
*/

int	pos_bottom_right(lemipc_t *lemipc)
{
	int	test = 0;
	char	*map;

	map = get_map(lemipc);
	test = lemipc->current_pos + 1;
	if (map[test] == '.')
		return (test);
	test = lemipc->current_pos + ROWS + 1;
	if (map[test] == '.')
		return (test);
	return (pos_top_left(lemipc));
}

/*
Obtention d'une nouvelle position
*/
int	get_new_pos(lemipc_t *lemipc)
{
	static	int	first = 0;
	int	near_enemy = 0;
	int	new = 0;

	if (first == 0)
		return (pos_first(lemipc, &first));
	near_enemy = get_near_one(lemipc);
	if (near_enemy == 0)
		return (-1);
	if (near_enemy < lemipc->current_pos)
		new = pos_top_left(lemipc);
	else
		new = pos_bottom_right(lemipc);
	return (new);
}
