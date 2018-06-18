/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
**	Name: philo.h
*/

#ifndef PHILO_H_
#define PHILO_H_

#include <pthread.h>

typedef struct	core
{
	int nbr_p;
	int nbr_e;
	int *chopsticks;
}	core_t;

typedef struct	philosopher
{
	pthread_t ctrl;
	int index;
	int eaten;
	char state;
}	philosopher_t;

extern core_t g_core;
extern pthread_mutex_t g_lock;

void action_rest(philosopher_t *);
void action_eat(philosopher_t *);
void action_think(philosopher_t *);

int philosopher(void);

#endif