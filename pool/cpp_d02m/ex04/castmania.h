/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        castmania.h
*/

#ifndef CASTMANIA_H_
# define CASTMANIA_H_

/*
** Enumerations
 */

typedef enum e_instruction_type
{
	PRINT_INT,
	PRINT_FLOAT,
	ADD_OPERATION,
	DIV_OPERATION
} 		instruction_type_t;

typedef enum e_div_type
{
	INTEGER,
	DECIMALE
}		div_type_t;

typedef enum e_add_type
{
	NORMAL,
	ABSOLUTE
}		add_type_t;

typedef enum e_output_type
{
	SILENT,
	VERBOSE
}		output_type_t;

/*
** Structures
*/

typedef struct s_integer_op
{
	int a;
	int b;
	int res;
}		integer_op_t;

typedef struct s_decimale_op
{
	int a;
	int b;
	float res;
} 		decimale_op_t;

typedef struct s_add
{
	add_type_t add_type;
	integer_op_t add_op;
}	add_t;

typedef struct s_div
{
	div_type_t div_type;
	void *div_op;
} div_t;

typedef struct s_instruction
{
	output_type_t output_type;
	void *operation;
} instruction_t;

/*
** Functions
*/

int	integer_div(int a, int b);
float	decimale_div(int a, int b);
void	exec_div(div_t *operation);

int	normal_add(int a, int b);
int	absolute_add(int a, int b);
void	exec_add(add_t *operation);

void	exec_operation(instruction_type_t instruction_type, void *data);
void	exec_instruction(instruction_type_t instruction_type, void *data);

#endif /* CASTMANIA_H_ */
