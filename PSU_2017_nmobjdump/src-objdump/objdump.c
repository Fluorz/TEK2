/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        objdump.c
*/

#include "./include/objdump.h"

static info_t	*init_info(void)
{
	info_t *new;

	new = malloc(sizeof(info_t));
	if (new == NULL)
		exit (84);
	return (new);
}

static void 	objdump(char *file)
{
	info_t *info;

	info = init_info();
	info = openfile(file, info);
	distrib_version(info);
	munmap(info->data, info->size);
	close(info->fd);
}

static void 	distrib_objdump(char **av)
{
	int	i = 1;

	while (av[i])
	{
		objdump(av[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		objdump("a.out");
	else
		distrib_objdump(av);
	return (0);
}
