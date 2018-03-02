/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        utils.c
*/

#include "../include/objdump.h"

char 	**alloc_tab(int size)
{
	int i = 0;
	char	**new;

	new = malloc(sizeof(char *) * size + 1);
	if (new == NULL)
		exit (84);
	while (i != size)
	{
		new[i] = malloc(sizeof(char) * 100);
		i++;
	}
	return (new);
}

int	get_len_max(int size)
{
	int i = 0;
	int j = 0;

	while (i < size)
	{
		j++;
		i += 16;
	}
	return (j);
}

char *arange_space(int index)
{
	char *str;

	str = malloc(sizeof(char) * 50);
	str[0] = '\0';
	for (; index < 16; index += 1)
		if (index % 4 == 0)
		{
			strcat(str, "   \0");
		}
		else
		{
			strcat(str, "  \0");
		}
	return (str);
}

void 	print_content_line(char *str)
{
	printf("Contents of section %s:\n", str);
}
