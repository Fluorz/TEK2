/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        main.c
*/

#include "../include/lemipc.h"

/*
Fonction pour ./lemipc --help
*/

static int 	help(void)
{
	printf("USAGE\n");
	printf("\t./lemipc PATH TEAM_NUMBER\n");
	printf("\n");
	printf("DESCRIPTION\n");
	printf("\tPATH\tpath you'll give to ftok\n");
	printf("\tTEAM_NUMBER team number of the current");
	printf(" champion (greater than 0)\n");
	return (0);
}

/*
Init la structure lemipc
*/

static	lemipc_t	*init_lemipc(void)
{
	lemipc_t *new;

	new = malloc(sizeof(lemipc_t));
	new->created = false;
	return (new);
}

/*
Recuperation des arguments données
*/

static lemipc_t		*get_args(char **av, lemipc_t *lemipc)
{
	lemipc->path = malloc(sizeof(char) * strlen(av[1]) + 1);
	lemipc->path = strcpy(lemipc->path, av[1]);
	lemipc->team_number = atoi(av[2]);
	if (lemipc->team_number <= 0)
		exit (84);
	return (lemipc);
}

/*
Lemipc
*/

static void 		lemipc(char **av)
{
	lemipc_t *lemipc;

	lemipc = init_lemipc();
	lemipc = get_args(av, lemipc);
	init_rand();
	create_shm(lemipc);
	create_sem(lemipc);
	game_loop(lemipc);
}

/*
Main avec les signaux
*/

int	main(int ac, char **av)
{
	if (ac <= 2)
		return (84);
	if (strcmp(av[1], "--help") == 0)
		return (help());
	signal(SIGSEGV, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	lemipc(av);
}
