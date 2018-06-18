/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        delete_ressources.c
*/

#include "../include/lemipc.h"

/*
delete les ipcs
*/

int	delete_shared_memory(lemipc_t *lemipc)
{
	shmctl(lemipc->shm_id, IPC_RMID, NULL);
	semctl(lemipc->sem_id, 0, IPC_RMID, NULL);
	return (0);
}

/*
Fonction pour delete un processus
*/

void 	cancel_processus(void)
{
	delete_pos(lemipc_g);
	if (lemipc_g->created == true) {
		printf("Cancel host\n");
		delete_shared_memory(lemipc_g);
	}
	exit (1);
}
