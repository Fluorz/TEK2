/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        mul_div.c
*/

void	add_mul_4param(int first, int second, int *sum, int *product)
{
	*sum = first + second;
	*product = first * second;
}

void	add_mul_2param(int *first, int *second)
{
	int	test_first;
	int	test_second;

	test_first = *first * *second;
	test_second = *first + *second;
	*first = test_second;
	*second = test_first;
}
