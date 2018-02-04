/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        menger.c
*/

#include "menger.h"

int		check_third_power(char **av)
{
	int	size = 0;
	int	level = 0;
	double	power = 0;

	size = my_getnbr(av[1]);
	level = my_getnbr(av[2]);
	power = level * level * level;
	if (size >= power)
		return (0);
	return (84);
}

void		recu_menger(int size, int level, int x, int y)
{
	int 	block = 0;

	if (!(size % 3) && level > 0 && level < size) {
		block = size / 3;
		printf("%03i %03i %03i\n", block, block + x, block + y);
		level--;
		recu_menger(block, level, x, y);
		recu_menger(block, level, x, y + block);
		recu_menger(block, level, x, y + 2 * block);
		recu_menger(block, level, x + block, y);
		recu_menger(block, level, x + block, y + 2 * block);
		recu_menger(block, level, x + 2 * block, y);
		recu_menger(block, level, x + 2 * block, y + block);
		recu_menger(block, level, x + 2 * block, y + 2 * block);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (84);
	if ((check_third_power(av)) != 0)
		return (84);
	recu_menger(my_getnbr(av[1]), my_getnbr(av[2]), 0, 0);
	return (0);
}
