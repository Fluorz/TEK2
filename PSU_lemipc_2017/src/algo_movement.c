/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
**        algo_movement.c
*/

#include "../include/lemipc.h"

/*
Display quand l'host est mort
Delete les ipcs
*/
static	int 	display_host(lemipc_t *lemipc)
{
	while (get_players(lemipc) > 1 && same_team(lemipc) != 0) {
		lemipc_g = lemipc;
		printf("\033[H\033[J");
		printf("HOST DEAD\n");
		printf("%s\n", get_map(lemipc));
	}
	printf("\033[H\033[J");
	printf("%s\n", get_map(lemipc));
	printf("TEAM WINNER : %d\n", last_team(lemipc));
	sleep(2);
	delete_shared_memory(lemipc);
	return (0);
}

/*
game loop avec le display
*/
int	game_loop_display(lemipc_t *lemipc)
{
	int	return_value;

	lemipc_g = lemipc;
	set_first_pos(lemipc);
	printf("\033[H\033[J");
	printf("%s\n", get_map(lemipc));
	printf("Waiting player...\n");
	sleep(4);
	while (get_players(lemipc) > 1 && same_team(lemipc) != 0) {
		lemipc_g = lemipc;
		printf("\033[H\033[J");
		return_value = set_new_position(lemipc);
		if (return_value == 2)
			return (display_host(lemipc));
		if (return_value == 1)
			return (1);
		printf("%s\n", get_map(lemipc));
	}
	return (display_host(lemipc));
}

/*
game_loop sans display
*/
int	game_loop(lemipc_t *lemipc)
{
	lemipc_g = lemipc;
	if (lemipc->created == true)
		return (game_loop_display(lemipc));
	set_first_pos(lemipc);
	while (get_players(lemipc) > 1 && same_team(lemipc) != 0) {
		lemipc_g = lemipc;
		if (set_new_position(lemipc) != 0)
			return (1);
	}
	printf("TEAM WINNER : %d\n", last_team(lemipc));
	return (0);
}
