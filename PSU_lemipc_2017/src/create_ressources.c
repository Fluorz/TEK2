/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        create_ressources.c
*/

#include "../include/lemipc.h"

/*
Creer la zone de partage
Inseérer la map dans la zone
Placez le joueur
delete la zone memoire
*/

int 	create_shm(lemipc_t *lemipc)
{
	if (open(lemipc->path, O_RDONLY) == -1)
		exit (84);
	lemipc->key = ftok(lemipc->path, 0);
	lemipc->shm_id = shmget(lemipc->key, 42, SHM_R | SHM_W);
	if (lemipc->shm_id == -1)
	{
		lemipc->shm_id = shmget(lemipc->key, 42,
			IPC_CREAT | SHM_R | SHM_W);
		printf("Created shm segment %d\n", lemipc->shm_id);
		lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
		sprintf((char *)lemipc->addr, "%s", put_maps());
		lemipc->created = true;
	}
	else
	{
		printf("Using shm segment %d\n", lemipc->shm_id);
		lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
	}
	return (0);
}

/*
Création sémaphore
*/

int	create_sem(lemipc_t *lemipc)
{
	lemipc->sem_id = semget(lemipc->key, 1, SHM_R | SHM_W);
	if (lemipc->sem_id == -1)
	{
		lemipc->sem_id = semget(lemipc->key, 1,
			IPC_CREAT | SHM_R | SHM_W);
		printf("Created sem %d\n", lemipc->sem_id);
		semctl(lemipc->sem_id, 0, SETVAL, 1);
	}
	else
	{
		printf("Using sem %d\n", lemipc->sem_id);
	}
	return (0);
}
