/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        main.c
*/

#include "strace.h"

int g_pid = 0;

static int print_usage(void)
{
	printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
	return (0);
}

static flags_t init_flags(void)
{
	flags_t flg;

	flg.s = false;
	flg.p = false;
	flg.av = NULL;
	return (flg);
}

static int get_flags(int ac, char **av, flags_t *flags)
{
	bool first_cmd = true;

	for (int i = 1; i < ac; i++) {
		if (strcmp(av[i], "-s") == 0)
			flags->s = true;
		else if (strcmp(av[i], "-p") == 0) {
			flags->p = true;
			if (av[i + 1])
				g_pid = atoi(av[i + 1]);
			else
				return (0);
		}
		else {
			if (first_cmd == true) {
				flags->av = av + i;
				first_cmd = false;
			}
		}
	}
	return (1);
}

void print_error(flags_t *flags)
{
		printf("strace: Can't stat '%s': ", flags->av[0]);
		printf("No such file or directory\n");
		exit(84);
}

int main(int ac, char **av)
{
	flags_t flags = init_flags();

	if (ac < 2)
		exit(84);
	if (strcmp(av[1], "--help") == 0)
		return (print_usage());
	if (!get_flags(ac, av, &flags))
		return (print_usage());
	if (flags.p == true || access(flags.av[0], F_OK) != -1)
		controller(&flags);
	else
		print_error(&flags);
	return (0);
}
