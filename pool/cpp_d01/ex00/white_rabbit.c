/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        white_rabbit.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		follow_the_white_rabbit(void)
{
	int	r = 0;
	int	n = 0;

	while (1) {
		r = random() % 37 + 1;
		n += r;
		printf("%s", (r == 8 || r == 16 || r == 24 || r == 26 ||
			 r == 32) ? "backward\n" : "");
		printf("%s", ((r >= 4 && r <= 6) || (r >= 17 && r <= 21)
		 || r == 28) ? "left\n" : "");
		printf("%s", (r == 10 || r == 15
			|| r == 23) ? "forward\n" : "");
		printf("%s", (r == 13 || r == 34 || r == 35
			 || r == 36) ? "right\n" : "");
		if (r == 1 || r == 37 || n >= 397) {
			printf("RABBIT!!!\n");
			return (n);
		}
	}
}
