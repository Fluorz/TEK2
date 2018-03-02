/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        main.c
*/

#include "./include/nm.h"

static void nm(char *file)
{
	info_t *info;

	info = init_info();
	info = openfile(file, info);
	distrib_version(info);
	munmap(info->data, info->size);
	close(info->fd);
}

static void distrib_nm(char **av, int ac)
{
	int i = 1;

	if (ac == 2)
	{
		nm(av[i]);
		return;
	}
	while (av[i])
	{
		printf("\n%s:\n", av[i]);
		nm(av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		nm("a.out");
	else
		distrib_nm(av, ac);
	return (0);
}
