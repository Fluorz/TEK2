/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        position.c
*/

#include "../include/lemipc.h"

/*
delete une position donnée
*/

static	void 	delete_position(char *map, int i, lemipc_t *lemipc)
{
	map[i] = '.';
	sprintf((char *)lemipc->addr, "%s", map);
}

/*
Regarde tous les joueurs en cours de jeu, pour savoir si il y en a pas un mort
*/

static	int	check_player(lemipc_t *lemipc)
{
	int	i = 0;
	char	*map;

	map = get_map(lemipc);
	if (map[lemipc->current_pos] == '.')
		return (0);
	while (map[i])
	{
		if (map[i] != '.' && map[i] != '\n') {
			if (check_position(map, i) != 0) {
				delete_position(map, i, lemipc);
				return (1);
			}
		}
		i++;
	}
	return (1);
}

/*
Set la premiere position en entrant dans le jeu
*/

void 	set_first_pos(lemipc_t *lemipc)
{
	int	pos = 0;

	lock_semaphore(lemipc);
	pos = get_new_pos(lemipc);
	set_new_pos(lemipc, pos, 1);
	unlock_semaphore(lemipc);
}

/*
Set une nouvelle position avec l'IA
*/

int 	set_new_position(lemipc_t *lemipc)
{
	int	pos = 0;

	lock_semaphore(lemipc);
	if (check_player(lemipc) == 0) {
		printf("Champion from team %d loose\n", lemipc->team_number);
		unlock_semaphore(lemipc);
		return (2);
	}
	pos = get_new_pos(lemipc);
	if (pos == -1)
		return (1);
	set_new_pos(lemipc, pos, 0);
	unlock_semaphore(lemipc);
	sleep(1);
	return (0);
}
