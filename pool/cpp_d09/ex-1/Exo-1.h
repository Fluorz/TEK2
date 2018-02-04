/*
** EPITECH PROJECT, 2018
** cpp_d09
** File description:
**        Exo-1.h
*/

#ifndef _EXO_
# define _EXO_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_cthulhu
{
	int	m_power;
	char	*m_name;
}		cthulhu_t;

typedef struct s_koala
{
	cthulhu_t m_parent;
	char m_isALegend;
}		koala_t;

cthulhu_t *NewCthulhu();
koala_t	*NewKoala(char *name, char _isALegend);
void	PrintPower(cthulhu_t *);
void	Attack(cthulhu_t *);
void	Sleeping(cthulhu_t *);
void	Eat(koala_t *);

#endif
