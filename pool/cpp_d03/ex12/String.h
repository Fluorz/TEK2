/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        string.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_string
{
	char	*str;
	void (*assign_c)(struct s_string *this, const char *s);
	void (*assign_s)(struct s_string *this, struct s_string const *str);
	void (*append_c)(struct s_string *this, const char *ap);
	void (*append_s)(struct s_string *this, struct s_string const *ap);
	char (*at)(struct s_string *this, size_t pos);
	void (*clear)(struct s_string *this);
	int (*size)(struct s_string *this);
	int (*compare_s)(struct s_string *this, struct s_string const *str);
	int (*compare_c)(struct s_string *this, const char * str);
	size_t (*copy)(struct s_string *this, char *s, size_t n, size_t pos);
	const char* (*c_str)(struct s_string *this);
	int (*empty)(struct s_string *this);
	int (*find_c)(struct s_string *this, char const *str, size_t pos);
	int (*find_s)(struct s_string *this,
		 struct s_string const *str, size_t pos);
	void (*insert_s)(struct s_string *this,
		 size_t pos, struct s_string const *str);
	void (*insert_c)(struct s_string *this, size_t pos, const char *str);
	int (*to_int)(struct s_string *this);
	void (*aff)(struct s_string *this);
	struct s_string *(*split_s)(struct s_string *this, char separator);
	char** (*split_c)(struct s_string *this, char separator);
	void (*join_s)(struct s_string *this, char delim, struct s_string *tab);
	void (*join_c)(struct s_string *this, char delim, const char **tab);
	struct s_string * (*substr)(struct s_string *this, int offset , int length );
}		String;

void	StringInit(String *this, const char *s);
void	StringDestroy(String *this);
