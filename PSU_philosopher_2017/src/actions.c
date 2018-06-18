/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
**        actions.c
*/

#include <unistd.h>
#include "extern.h"
#include "philo.h"

void action_rest(philosopher_t *philo)
{
	pthread_mutex_unlock(&g_lock);
	lphilo_sleep();
	philo->state = 'R';
}

void action_eat(philosopher_t *philo)
{
	philo->state = 'E';
	g_core.chopsticks[philo->index] = 1;
	lphilo_take_chopstick(&g_lock);
	g_core.chopsticks[(philo->index + 1) % g_core.nbr_p] = 1;
	lphilo_take_chopstick(&g_lock);
	pthread_mutex_unlock(&g_lock);
	philo->eaten += 1;
	lphilo_eat();
	pthread_mutex_lock(&g_lock);
	g_core.chopsticks[philo->index] = 0;
	lphilo_release_chopstick(&g_lock);
	g_core.chopsticks[(philo->index + 1) % g_core.nbr_p] = 0;
	lphilo_release_chopstick(&g_lock);
	pthread_mutex_unlock(&g_lock);
}

void action_think(philosopher_t *philo)
{
	philo->state = 'T';
	g_core.chopsticks[philo->index] = 1;
	lphilo_take_chopstick(&g_lock);
	pthread_mutex_unlock(&g_lock);
	lphilo_think();
	while (philo->state != 'E') {
		pthread_mutex_lock(&g_lock);
		if (g_core.chopsticks[(philo->index + 1) % g_core.nbr_p] == 0)
			action_eat(philo);
		else
			pthread_mutex_unlock(&g_lock);
	}
}
