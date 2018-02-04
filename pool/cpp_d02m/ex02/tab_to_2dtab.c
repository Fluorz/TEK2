/*
** EPITECH PROJECT, 2018
** ex02
** /home/lecherbonnier/Projet/TEK2/pool/cpp_d02/ex02
** tab_to_2tab.c
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(int *tab, int length, int width, int ***res)
{
	int	i = 0;
	int	y = 0;
	int	k = 0;
	int	max = length * width;

	*res = malloc(sizeof(int*) * length + 1);
	while (i != length && k != max) {
		(*res)[i] = malloc(sizeof(int) * width);
		while (y != width && k != max) {
			(*res)[i][y] = tab[k];
			y++;
			k++;
		}
		y = 0;
		i++;
	}
}
