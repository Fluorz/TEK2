/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
**        main.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
core_t g_core;

void print_usage(void)
{
	printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
	printf("DESCRIPTION\n\t-p nbr_p number of philosophers\n");
	printf("\t-e nbr_e maximum number times a philosopher");
	fflush(stdout);
	printf(" eats before exiting the program\n");
}

void init_core(int ac, char **av)
{
	for (int i = 0; i < ac; i++) {
		if (strcmp(av[i], "-p") == 0 && av[i + 1])
			g_core.nbr_p = atoi(av[i + 1]);
		if (strcmp(av[i], "-e") == 0 && av[i + 1])
			g_core.nbr_e = atoi(av[i + 1]);
	}
	g_core.chopsticks = calloc(g_core.nbr_p, sizeof(int));
	if (!g_core.chopsticks)
		exit(84);
	if (g_core.nbr_e < 0 || g_core.nbr_p < 0)
		exit(84);
}

int main(int ac, char **av)
{
	int status = 0;

	if (ac == 2) {
		if (strcmp(av[1], "--help") == 0)
			print_usage();
		return (0);
	}
	else {
		RCFStartup(ac, av);
		init_core(ac, av);
		status = philosopher();
	}
	RCFCleanup();
	free(g_core.chopsticks);
	return (status);
}
