/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        pyramid.c
*/

int	pyramid_path(int size, int **map)
{
	unsigned int	i = 1;
	unsigned int	somme = 0;
	unsigned int	last_x = 0;

	somme += map[0][0];
	while (i != size && i + 1 < size) {
		if (map[i][last_x] > map[i][last_x + 1]) {
			somme += map[i][last_x + 1];
			last_x += 1;
		}
		else {
		somme += map[i][last_x];
		}
		i = i + 1;
	}
	return (somme);
}
