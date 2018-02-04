/*
** EPITECH PROJECT, 2018
** ex03
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex03
** func_ptr.c
*/

#include "func_ptr.h"

void 	print_normal(char *str)
{
	printf("%s\n", str);
}

void 		print_reverse(char *str)
{
	int	i = strlen(str) - 1;

	while (i >= 0) {
		printf("%c", str[i]);
		i--;
	}
	fflush(stdout);
	printf("\n");
}

void 		print_upper (char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 97 && str[i] <= 122)
			printf("%c", str[i] - 32);
		else
			printf("%c", str[i]);
		i++;
	}
	fflush(stdout);
	printf("\n");
}

void 		print_42 (char *str)
{
	(void)str;
	printf("42\n");
}

void do_action(action_t action, char *str)
{
	int	i = 0;

	tmp_action_t	tmp_action[] = {
		{PRINT_NORMAL, &print_normal},
		{PRINT_REVERSE, &print_reverse},
		{PRINT_42, &print_42},
		{PRINT_UPPER, &print_upper},
	};

	while (i != 4) {
		if (action == tmp_action[i].action) {
			(*tmp_action[i].func)(str);
			break;
		}
		i++;
	}
}
