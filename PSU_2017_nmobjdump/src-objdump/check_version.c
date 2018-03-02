/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        check_version.c
*/

#include "./include/objdump.h"

info_t 	*openfile(char *file, info_t *info)
{
	void *data;
	int	fd;
	struct stat file_infos;

	fd = open(file, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "objdump: \'%s\': No such file\n", file);
		exit (84);
	}
	if (fstat(fd, &file_infos))
		exit (84);
	data = mmap(0, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (data == MAP_FAILED)
		exit (84);
	info->fd = fd;
	info->data = data;
	info->file = malloc(sizeof(char) * strlen(file) + 1);
	info->file = strcpy(info->file, file);
	info->size = file_infos.st_size;
	return (info);
}

static void 	error_handler32(info_t *info)
{
	Elf32_Ehdr *elf;

	elf = info->data;
	if (elf->e_ident[EI_MAG0] != ELFMAG0 ||
		elf->e_ident[EI_MAG1] != ELFMAG1 ||
		elf->e_ident[EI_MAG2] != ELFMAG2 ||
		elf->e_ident[EI_MAG3] != ELFMAG3 ||
		(elf->e_type != ET_REL &&
			elf->e_type !=  ET_EXEC &&
			elf->e_type != ET_DYN)) {
		fprintf(stderr, "objdump: %s: File format not recognized\n",
			info->file);
		exit (84);
	}
	if (elf->e_phoff > info->size ||
	elf->e_shoff > info->size) {
	fprintf(stderr, "objdump: %s: File truncated\n",
		info->file);
	exit (84);
	}
}

static void 	error_handler64(info_t *info)
{
	Elf64_Ehdr *elf;

	elf = info->data;
	if (elf->e_ident[EI_MAG0] != ELFMAG0 ||
		elf->e_ident[EI_MAG1] != ELFMAG1 ||
		elf->e_ident[EI_MAG2] != ELFMAG2 ||
		elf->e_ident[EI_MAG3] != ELFMAG3 ||
		(elf->e_type != ET_REL &&
			elf->e_type !=  ET_EXEC &&
			elf->e_type != ET_DYN)) {
		fprintf(stderr, "objdump: %s: File format not recognized\n",
			info->file);
		exit (84);
	}
	if (elf->e_phoff > info->size ||
	elf->e_shoff > info->size) {
	fprintf(stderr, "objdump: %s: File truncated\n",
		info->file);
	exit (84);
	}
}

void 	distrib_version(info_t *info)
{
	Elf32_Ehdr	*tmp;

	tmp = (Elf32_Ehdr*)info->data;
	if (tmp->e_ident[EI_CLASS] == ELFCLASS32) {
		error_handler32(info);
		elf32_format(info);
	}
	else if (tmp->e_ident[EI_CLASS] == ELFCLASS64) {
		error_handler64(info);
		elf64_format(info);
	}
	else {
		fprintf(stderr, "objdump: %s: File format not recognized\n",
		info->file);
		exit (84);
	}
}
