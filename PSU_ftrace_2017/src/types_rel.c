/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        types_rel.c
*/

#include "strace.h"

char *print_unsigned(unsigned int addr)
{
	char *buff = malloc(sizeof(char) * 256);

	sprintf(buff, "%lu", (unsigned long) addr);
	return (buff);
}

char *print_int(unsigned int addr)
{
	char *buff = malloc(sizeof(char) * 256);

	sprintf(buff, "%d", addr);
	return (buff);
}

char *get_string_at(long addr)
{
	char *str = malloc(sizeof(char) * 256);
	int read = 0;
	unsigned long temp;

	while (true) {
		temp = ptrace(PTRACE_PEEKDATA, g_pid, addr + read, NULL);
		if (errno != 0)
			return ("");
		memcpy(str + read, &temp, sizeof(temp));
		if (memchr(&temp, 0, sizeof(temp)) != NULL)
			break;
		read += sizeof(temp);
	}
	return (str);
}

char *print_string(unsigned int addr)
{
	char *buff = malloc(sizeof(char) * 256);
	char *temp = get_string_at(addr);
	char *new = malloc(sizeof(char) * 256);
	int j = 0;

	for (size_t i = 0; i < strlen(temp); i++) {
		new[j] = temp[i];
		if (temp[i] == '\n') {
			new[j] = '\\';
			new[j + 1] = 'n';
			j++;
		}
		j++;
	}
	sprintf(buff, "\"%s\"", new);
	return (buff);
}

char *print_char(unsigned int addr)
{
	char *buff = malloc(sizeof(char) * 256);

	sprintf(buff, "%c", addr);
	return (buff);
}
