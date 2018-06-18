/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
**        philo.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void *cure_the_famine(void *arg)
{
	philosopher_t *philo = (philosopher_t *) arg;
	int left;
	int right;

	while (1) {
		pthread_mutex_lock(&g_lock);
		left = g_core.chopsticks[philo->index];
		right = g_core.chopsticks[(philo->index + 1) % g_core.nbr_p];
		if (left == 0 && right == 0 && philo->state != 'E')
			action_eat(philo);
		else if ((left == 0 || right == 0) && philo->state == 'E')
			action_think(philo);
		else
			action_rest(philo);
		if (philo->eaten >= g_core.nbr_e)
			break;
	}
	return (NULL);
}

void init_philos(philosopher_t **philos)
{
	*philos = malloc(sizeof(philosopher_t) * g_core.nbr_p);
	if (!(*philos))
		exit(84);
	for (int i = 0; i < g_core.nbr_p; i++) {
		(*philos)[i].index = i;
		(*philos)[i].eaten = 0;
		(*philos)[i].state = 'R';
	}
}

void join_philos(philosopher_t *philos)
{
	for (int i = 0; i < g_core.nbr_p; i++) {
		pthread_join(philos[i].ctrl, NULL);
	}
}

int philosopher(void)
{
	philosopher_t *philos;

	init_philos(&philos);
	for (int i = 0; i < g_core.nbr_p; i++) {
		pthread_create(&philos[i].ctrl, NULL,
		cure_the_famine, &philos[i]);
	}
	join_philos(philos);
	free(philos);
	return (0);
}
