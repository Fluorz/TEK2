/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        strace.h
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <fcntl.h>
# include <unistd.h>
# include <sys/user.h>
# include <sys/reg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ptrace.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <wait.h>
# include <errno.h>

# define UNSIGNED_INT 1
# define INT 2
# define STRING 3
# define CHAR 4
# define OTHER 5

typedef struct	s_system_call
{
	int rax;
	char *name;
	int nparams;
	int param_type1;
	int param_type2;
	int param_type3;
	int param_type4;
	int param_type5;
	int param_type6;
}	system_call_t;

typedef struct	s_flags
{
	bool s;
	bool p;
	char **av;
}	flags_t;

extern const int LONG_SIZE;

typedef struct	s_params
{
	int i;
	int val;
}	params_t;

typedef struct	s_types_rel
{
	int value;
	char *(*print_related)(unsigned int);
}	types_rel_t;

typedef struct	s_functions
{
	char *name;
	void (*spec_func)(flags_t *, struct user_regs_struct *data);
}	functions_t;

typedef struct	s_open_flags
{
	int flag;
	char *to_print;
}	open_flags_t;

extern const system_call_t SYSCALL_NAMES[];
extern int g_pid;
extern const types_rel_t g_types_rel[];

int print_specifics(flags_t *, struct user_regs_struct *data);

params_t *get_params(struct user_regs_struct *data);

char *print_string(unsigned int);
char *get_string_at(long addr);
void print_detailed(struct user_regs_struct *data);
void print_syscall(struct user_regs_struct *data);

void controller(flags_t *flags);

/* Function pointers */
char *print_unsigned(unsigned int addr);
char *print_int(unsigned int addr);
char *print_string(unsigned int addr);
char *print_char(unsigned int addr);

void print_space(char **syscall);

/* Specific functions (func pointers) */
void access_func(flags_t *, struct user_regs_struct *data);
void open_func(flags_t *, struct user_regs_struct *data);
void write_func(flags_t *flags, struct user_regs_struct *data);

#endif
