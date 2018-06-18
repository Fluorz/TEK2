/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        semaphore_check.c
*/

#include "../include/lemipc.h"

/*
Lock semaphore
*/

void 	lock_semaphore(lemipc_t *lemipc)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = -1;
	semop(lemipc->sem_id, &sops, 1);
}

/*
Unlock semaphore
*/
void 	unlock_semaphore(lemipc_t *lemipc)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = 1;
	semop(lemipc->sem_id, &sops, 1);
}
