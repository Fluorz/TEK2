/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
**        nm.h
*/

#ifndef _NM_
# define _NM_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <string.h>

typedef struct s_32
{
	Elf32_Ehdr	*elf;
	Elf32_Shdr	*shdr;
	Elf32_Sym	*symtab;
	Elf32_Shdr	*strsymsection;
	Elf32_Shdr	*symsection;
	char		*strsymtab;
	char		*strtab;
	Elf32_Sym	**symtab_cpy;
}	s32_t;

typedef struct s_64
{
	Elf64_Ehdr	*elf;
	Elf64_Shdr	*shdr;
	Elf64_Sym	*symtab;
	Elf64_Shdr	*strsymsection;
	Elf64_Shdr	*symsection;
	char		*strsymtab;
	char		*strtab;
	Elf64_Sym	**symtab_cpy;
}	s64_t;

typedef struct s_info
{
	char *file;
	int fd;
	size_t size;
	void *data;
}	info_t;

typedef struct	s_flags
{
	unsigned int	x;
	uint32_t	type;
	uint32_t	flags;
	char		ch;
}	flags_t;

typedef struct	s_type
{
	char		ch;
	uint32_t	type;
	uint64_t	flags;
}	type_t;

/*Check Version*/
info_t *openfile(char *file, info_t *info);
void distrib_version(info_t *info);
info_t *init_info(void);

/*elf32_format*/
void check_header32(info_t *info);
void elf32_format(info_t *info);
Elf32_Sym **get_symtab_cpy32(Elf32_Sym *symtab, unsigned int size);

/*elf64_format*/
void check_header64(info_t *info);
void elf64_format(info_t *info);
Elf64_Sym **get_symtab_cpy(Elf64_Sym *symtab, unsigned int size);
s64_t *init_elf_64(void *data);
void set_sym_64(s64_t *elf);

#endif
