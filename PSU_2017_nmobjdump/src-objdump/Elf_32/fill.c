/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        fill.c
*/

#include "../include/objdump.h"

static char	*get_first(Elf32_Shdr section, char *line, int index)
{
	char str[150];
	int r;

	line[0] = ' ';
	r = sprintf(str, "%04x" , (unsigned int)section.sh_addr + index);
	line[1] = '\0';
	strcat(line, str);
	line[r + 1] = ' ';
	line[r + 2] = '\0';
	return (line);
}

static void 	fill_hexa32(source32_t *source, Elf32_Shdr section, int line,
		int index)
{
	char str[100];
	int	i;
	void 	*start;

	start = (void*)source->elf;
	source->tab[line] = get_first(section, source->tab[line], index);
	if (strlen(source->tab[line]) == 5)
		source->tab[line][5] = ' ';
	for (i = 0; index + i < (int)section.sh_size; i += 1) {
		if (i != 0 && i % 16 == 0) {
			strcat(source->tab[line], arange_space(i));
			return;
		}
		if (i % 16 != 0 && i % 4 == 0)
			strcat(source->tab[line], " ");
		sprintf(str, "%02x", *(unsigned char *)(start +
			section.sh_offset + index + i));
		strcat(source->tab[line], str);
	}
	strcat(source->tab[line], arange_space(i));
}

static void 	fill_ascii32(source32_t *source, Elf32_Shdr section,
		int line, int index)
{
	char str[16];
	int i;
	void *start;

	start = (void*)source->elf;
	for (i = 0; index + i < (int)section.sh_size; i += 1) {
		if (i != 0 && i % 16 == 0)
			return;
		if (*(char *)(start + section.sh_offset + i + index) >= 32 &&
		*(char *)(start + section.sh_offset + i + index) < 127)	{
				sprintf(str, "%c", *(char *)(start +
					section.sh_offset + i + index));
				strcat(source->tab[line], str);
			}
		else
			strcat(source->tab[line], ".");
	}
	for (; (index + i) % 16 != 0; i += 1)
		strcat(source->tab[line], " ");
}

void 	print_32(source32_t *source, Elf32_Shdr section)
{
	int j = 0;
	unsigned int i = 0;

	source->tab = alloc_tab(get_len_max(section.sh_size));
	while (i < section.sh_size)
	{
		fill_hexa32(source, section, j, i);
		strcat(source->tab[j], "  ");
		fill_ascii32(source, section, j, i);
		printf("%s\n", source->tab[j]);
		j++;
		i += 16;
	}
	source->tab[j] = NULL;
}
