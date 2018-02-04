/*
** EPITECH PROJECT, 2018
** ex03
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex03
** func_ptr.h
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "func_ptr_enum.h"

void print_normal (char *str);
void print_reverse (char *str);
void print_upper (char * str);
void print_42 (char * str);
void do_action(action_t action, char *str);

typedef struct s_tmp_action
{
	action_t	action;
	void (*func)(char *);
}		tmp_action_t;
