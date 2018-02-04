/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        string.c
*/

#include "String.h"

static void join_c(String *this, char delim, const char **tab);
static void join_s(String * this, char delim, String *tab);
static int		count_word(char *str, char separe);
static char		**my_str_to_wordtab(char *str, char separe);
static void aff(String *this);
char ** split_c (String * this , char separator);
String *split_s(String * this, char separator);
static int to_int ( String *this);
static int find_c(String *this, char const *str, size_t pos);
static int find_s(String *this, const String *str, size_t pos);
static int empty(String *this);
static const char *c_str(String *this);
static size_t copy(String * this, char *s, size_t n, size_t pos);
static int compare_c(String *this, const char * str);
static int compare_s(String *this, const String *str);
static int size(String *this);
static void clear(String *this);
static char at(String *this, size_t pos);
static void append_c(String *this, const char *ap);
static void append_s(String *this, const String *ap);
void insert_c (String *this, size_t pos, const char *str);
void insert_s(String * this, size_t pos, const String *str);
static void assign_c(String *this, const char *s);
static void assign_s(String *this , const String *str);

static void join_c(String *this, char delim, const char **tab)
{
	(void)this;
	(void)delim;
	(void)tab;
	return;
}

static void join_s(String * this, char delim, String *tab)
{
	(void)this;
	(void)delim;
	(void)tab;
	return;
}

static int		count_word(char *str, char separe)
{
	int		i = 0;
	int		count = 1;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
	while (str[i]) {
		if (str[i] == ' ' || str[i] == '\t' || str[i] == separe) {
			while (str[i] == ' ' || str[i] == '\t' || str[i] == separe) {
				i++;
			}
			if (str[i])
				count++;
		}
		if (str[i]) {
			i++;
		}
	}
	return (count);
}

static char		**my_str_to_wordtab(char *str, char separe)
{
	char		**tab;
	int		i = 0;
	int		j = 0;
	int		k;

	if ((tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1))))
	 == NULL)
	return (NULL);
	while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
		i++;
	while (str[i]) {
	  if ((tab[j] = malloc(sizeof(**tab) * (strlen(str) + 1))) == NULL)
	return (NULL);
	k = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
	tab[j][k++] = str[i++];
	tab[j++][k] = '\0';
	while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
	}
	tab[j] = NULL;
	return (tab);
}

static void aff(String *this)
{
	printf("%s", this->str);
	fflush(stdout);
}

char ** split_c (String * this , char separator)
{
	char **tab = NULL;

	tab = my_str_to_wordtab(this->str, separator);
	return (tab);
}

String *split_s(String * this, char separator)
{
	String *split;
	int i = 0;
	char **tab = NULL;

	tab = split_c(this, separator);
	while (tab[i++]);
	split = malloc(i * sizeof(String));
	while (i--) {
		StringInit(&split[i], tab[i]);
	}
	return (split);
}

static int to_int ( String *this)
{
	if (this->str) {
		return (atoi(this->str));
	}
	return (-1);
}

static int find_c(String *this, char const *str, size_t pos)
{
	char	*occu;

	if (this->str && strlen(this->str) > pos) {
		occu = strstr(&this->str[pos], str);
		if (occu) {
			return (occu - this->str);
		}
	}
	return (-1);
}

static int find_s(String *this, const String *str, size_t pos)
{
	return (find_c(this, str->str, pos));
}

static int empty(String *this)
{
	int	i = 0;

	if (this->str == NULL)
	return (1);
	if (this->str) {
		while (this->str[i]) {
			i++;
		}
		if (i == 0) {
			return (1);
		}
		else
		return (-1);
	}
	return (-1);
}

static const char *c_str(String *this)
{
	if (this->str) {
		return (this->str);
	}
	return (NULL);
}

static size_t copy(String *this, char *s, size_t n, size_t pos)
{
	int i = 0;

	if (this->str && s) {
		while (n-- && pos < strlen(this->str)) {
			s[i] = this->str[pos];
			i++;
			pos++;
		}
	}
	return (i);
}

static int compare_c(String *this, const char * str)
{
	return (strcmp(this->str, str));
}

static int compare_s(String *this, const String *str)
{
	return (compare_c(this, str->str));
}

static int size(String *this)
{
	unsigned int	len = 0;

	if (this->str) {
		len = strlen(this->str);
		return (len);
	}
	else
	return (-1);
}

static void clear(String *this)
{
	if (!this)
		return;
	else if (!this->str) {
		this->str = realloc(this->str, 1);
		this->str[0] = '\0';
	}
	if (this->str && this->str[0] != '\0') {
		this->str[0] = '\0';
	}
	else
	return;
}

static char at(String *this, size_t pos)
{
	unsigned int	len = 0;

	if (!this->str || !this || this->str[0] == '\0')
	return (-1);
	len = strlen(this->str) - 1;
	if (pos > len || pos < 0.0)
	return (-1);
	if (this->str && pos <= len) {
		return (this->str[pos]);
	}
	else
	return (-1);
}

static void append_c(String *this, const char *ap)
{
	if (ap && ap[0] != '\0')
	{
		this->str = realloc(this->str, strlen(ap));
		this->str = strcat(this->str, ap);
	}
	return ;
}

static void append_s(String *this, const String *ap)
{
	append_c(this, ap->str);
}

void insert_c (String *this, size_t pos, const char *str)
{
	unsigned int len = 0;
	unsigned int zero = 0;

	len = strlen(str);
	if (this->str && pos > strlen(this->str)) {
		return (append_c(this, str));
	}
	if ((strlen(this->str) - len - 1) < zero) {
		this->str = realloc(this->str, strlen(this->str) + len + 1);
	}
	strcpy(&this->str[pos] + len, &this->str[pos]);
	strncpy(&this->str[pos], str, len);
}

void insert_s(String * this, size_t pos, const String *str)
{
	insert_c(this, pos, str->str);
}

static void assign_c(String *this, const char *s)
{
	StringDestroy(this);
	StringInit(this, s);
}

static void assign_s(String *this , const String *str)
{
	assign_c(this, str->str);
}

String *substr(String *this, int offset, int length)
{
	(void)this;
	(void)offset;
	(void)length;
	return (this);
}

void StringInit (String *this, const char *s)
{
	if (s) {
		this->str = malloc(sizeof(char) * strlen(s) + 1);
		this->str = strcpy(this->str, s);
	}
	else
		this->str = NULL;
	this->assign_c = &assign_c;
	this->assign_s = &assign_s;
	this->append_c = &append_c;
	this->append_s = &append_s;
	this->at = &at;
	this->clear = &clear;
	this->size = &size;
	this->compare_s = &compare_s;
	this->compare_c = &compare_c;
	this->copy = &copy;
	this->c_str = &c_str;
	this->empty = &empty;
	this->find_c = &find_c;
	this->find_s = &find_s;
	this->insert_s = &insert_s;
	this->insert_c = &insert_c;
	this->to_int = &to_int;
	this->split_s = &split_s;
	this->split_c = &split_c;
	this->join_c = &join_c;
	this->join_s = &join_s;
	this->aff = &aff;
}

void StringDestroy(String *this)
{
	if (this == NULL)
		return;
	if (this->str) {
		this->str = NULL;
		free(this->str);
	}
}
