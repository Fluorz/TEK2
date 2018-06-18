/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        get.c
*/

#include "../include/lemipc.h"

/*
Obtient le nombre de player
*/

int	get_players(lemipc_t *lemipc)
{
	char	*str;
	int	i = 0;
	int	numbers = 0;

	str = get_map(lemipc);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n')
			numbers++;
		i++;
	}
	return (numbers);
}

/*
Obtient la map en format char *
*/

char	*get_map(lemipc_t *lemipc)
{
	key_t	key;
	int	id;
	char *str;

	key = ftok(lemipc->path, 0);
	id = shmget(key, 42, SHM_R | SHM_W);
	if (id == -1)
		return (NULL);
	if (((char *)lemipc->addr) == NULL)
		return (NULL);
	if ((strlen((char *)lemipc->addr) == 0))
		return (NULL);
	str = malloc(sizeof(char) * strlen((char *)lemipc->addr) + 10);
	str = strcpy(str, (char*)lemipc->addr);
	return (str);
}

/*
set une nouvelle position
*/

void 	set_new_pos(lemipc_t *lemipc, int pos, int first)
{
	char	*map = NULL;

	if (pos == -1)
		return;
	map = get_map(lemipc);
	if (map == NULL)
		return;
	if (first == 0)
		map[lemipc->current_pos] = '.';
	map[pos] = lemipc->team_number + 48;
	sprintf((char *)lemipc->addr, "%s", map);
	lemipc->current_pos = pos;
}

/*
delete une position
*/

void 	delete_pos(lemipc_t *lemipc)
{
	char	*map;

	map = get_map(lemipc);
	if (map == NULL)
		return;
	map[lemipc->current_pos] = '.';
	sprintf((char *)lemipc->addr, "%s", map);
}
