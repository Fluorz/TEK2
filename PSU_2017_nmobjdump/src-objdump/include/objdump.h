/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        objdump.h
*/

#ifndef _OBJDUMP_
# define _OBJDUMP_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <string.h>
#include <stdbool.h>
#include "flags.h"

typedef struct s_info
{
	char *file;
	int fd;
	size_t size;
	void *data;
}	info_t;

typedef struct s_flags
{
	bool exec_p;
	bool has_reloc;
	bool has_syms;
	bool dynamic;
	bool d_paged;
	bool checked;
	uint32_t total;
}	flags_t;

typedef struct s_source
{
	Elf64_Shdr	*section_tab;
	Elf64_Shdr	section_string;
	char		*string;
	Elf64_Ehdr	*elf;
	char **tab;
}	source_t;

typedef struct s_source32
{
	Elf32_Shdr	*section_tab;
	Elf32_Shdr	section_string;
	char		*string;
	Elf32_Ehdr	*elf;
	char **tab;
}	source32_t;

info_t	*openfile(char *file, info_t *info);
void 	elf32_format(info_t *info);
void 	elf64_format(info_t *info);
void 	error_handler(info_t *info);
void 	distrib_version(info_t *info);
void 	print_source64(info_t *info);
void 	print_source32(info_t *info);

int check_section(Elf64_Shdr section);
char 	**alloc_tab(int size);
int	get_len_max(int size);
char *arange_space(int index);
void 	print_content_line(char *str);
int check_section32(Elf32_Shdr section, Elf32_Ehdr *elf);

void 	print_flags64(Elf64_Ehdr *elf);
void 	print_flags32(Elf32_Ehdr *elf);

void 	print_32(source32_t *source, Elf32_Shdr section);
void 	print_source(source_t *source, Elf64_Shdr section);

#endif
