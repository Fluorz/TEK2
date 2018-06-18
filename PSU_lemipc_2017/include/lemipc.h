/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        lemipc.h
*/

#ifndef _LEMIPC_
# define _LEMIPC_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>

#define LINES 10
#define ROWS 10

typedef struct lemipc_s
{
	int	team_number;
	char	*path;
	key_t	key;
	int	shm_id;
	void 	*addr;
	int 	sem_id;
	int	current_pos;
	bool	created;
}	lemipc_t;

/*Strucure globale utilisé pour les signaux uniquement*/
struct	lemipc_s *lemipc_g;

int	create_shm(lemipc_t *lemipc);
const char	*put_maps(void);
int	game_loop(lemipc_t *lemipc);
int	get_players(lemipc_t *lemipc);
char	*get_map(lemipc_t *lemipc);
void 	lock_semaphore(lemipc_t *lemipc);
void 	unlock_semaphore(lemipc_t *lemipc);
int 	get_new_pos(lemipc_t *lemipc);
void 	set_new_pos(lemipc_t *lemipc, int pos, int);
void	init_rand(void);
int	delete_shared_memory(lemipc_t *lemipc);
void 	delete_pos(lemipc_t *lemipc);
int	same_team(lemipc_t *lemipc);
int	pos_top_left(lemipc_t *lemipc);
int	pos_bottom_right(lemipc_t *lemipc);
int	last_team(lemipc_t *lemipc);
void 	sig_handler(int sig);
int	check_same_team(char buff[9]);
int	create_sem(lemipc_t *lemipc);
int	check_position(char *map, int i);
void 	set_first_pos(lemipc_t *lemipc);
int 	set_new_position(lemipc_t *lemipc);
void 	cancel_processus(void);
#endif
