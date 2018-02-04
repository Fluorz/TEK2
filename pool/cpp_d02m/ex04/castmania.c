/*
** EPITECH PROJECT, 2018
** ex04
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex04
** castmania.c
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
	instruction_t *instruction_data = (instruction_t*) data;

	if (instruction_type == ADD_OPERATION) {
		instruction_data = (instruction_t*) data;
		exec_add(instruction_data->operation);
		if (instruction_data->output_type == VERBOSE) {
			printf("%d\n",
			((add_t*)instruction_data->operation)->add_op.res
	);
	}
}
	if (instruction_type == DIV_OPERATION) {
		instruction_data = (instruction_t*) data;
		exec_div(instruction_data->operation);
		if (instruction_data->output_type == VERBOSE) {
		printf("%d\n",
		((integer_op_t*)
		((div_t*)instruction_data->operation)->div_op)->res
	);
	}
}
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
	if (instruction_type == PRINT_INT) {
		printf("%i\n", *((int *) data));
	}
	else if (instruction_type == PRINT_FLOAT) {
		printf("%f\n", *((float *) data));
	}
	else
		exec_operation(instruction_type, data);
}
