/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        tools.c
*/

#include "../include/lemipc.h"

/*
Initialisation du random
*/

void		init_rand(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
Regarde si il y a qu'une seule team en vie
*/

int	same_team(lemipc_t *lemipc)
{
	int	result = 0;
	char	*map;
	char	stock = 0;
	int	i = 0;

	map = get_map(lemipc);
	if (map == NULL)
		return (0);
	while (map[i])
	{
		if (map[i] != '.' && map[i] != '\n' && stock != map[i])
		{
			stock = map[i];
			result++;
		}
		i++;
	}
	if (result == 1)
		return (0);
	return (1);
}

/*
Return la team gagnante
*/

int	last_team(lemipc_t *lemipc)
{
	int	i = 0;
	char	last = 0;
	char	*map;

	map = get_map(lemipc);
	if (map == NULL)
		return (0);
	while (map[i])
	{
		if (map[i] != '.' && map[i] !='\n')
			last = map[i];
		i++;
	}
	return (last - 48);
}

/*
Sig handler pour les signaux :
Sigint ; Sigquit ; Sigsev
*/

void 	sig_handler(int sig)
{
	switch (sig) {
		case 2:
		cancel_processus();
		break;
		case 3:
		cancel_processus();
		break;
		case 11:
		cancel_processus();
	}
}

/*
Check dans le buffer des voisins si il y a 2 voisins d'une meme equipe
*/

int	check_same_team(char buff[9])
{
	int	i = 0;
	int	j = 0;

	while (i != 9)
	{
		j = 0;
		while (j != 9)
		{
			if (i != j && buff[i] == buff[j] && buff[i] != 'L')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
