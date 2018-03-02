/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        check_version.c
*/

#include "./include/nm.h"

info_t *openfile(char *file, info_t *info)
{
	void*	data;
	int	fd;
	struct	stat file_infos;

	fd = open(file, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "nm: \'%s\': No such file\n", file);
		exit (84);
	}
	if (fstat(fd, &file_infos))
		exit (84);
	data = mmap(0, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (data == MAP_FAILED)
		exit (84);
	info->fd = fd;
	info->size = file_infos.st_size;
	info->data = data;
	info->file = malloc(sizeof(char) * strlen(file) + 1);
	info->file = strcpy(info->file, file);
	return (info);
}

void distrib_version(info_t *info)
{
	Elf32_Ehdr	*tmp;

	tmp = (Elf32_Ehdr*)info->data;
	if (tmp->e_ident[EI_CLASS] == ELFCLASS32)
	{
		elf32_format(info);
	}
	else if (tmp->e_ident[EI_CLASS] == ELFCLASS64)
	{
		elf64_format(info);
	}
	else {
		fprintf(stderr, "nm: %s: File format not recognized\n",
		info->file);
		exit (84);
	}
}

info_t *init_info(void)
{
	info_t *new;

	new = malloc(sizeof(info_t));
	if (new == NULL)
		exit (84);
	return (new);
}
