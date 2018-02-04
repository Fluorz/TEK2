/*
** EPITECH PROJECT, 2018
** cpp_d09
** File description:
**        Exo-1.c
*/

#include "Exo-1.h"

static	void	CthulhuInitializer(cthulhu_t *this);
static	void	KoalaInitializer(koala_t *this, char *_name,
	char _isALegend);

static	void	CthulhuInitializer(cthulhu_t *this)
{
	if (this == NULL)
		return;
	this->m_name = malloc(sizeof(char) * strlen("Cthulhu"));
	if (this->m_name == NULL)
		return;
	this->m_name = strdup("Cthulhu");
	this->m_power = 42;
}

cthulhu_t	*NewCthulhu()
{
	cthulhu_t *new;

	new = malloc(sizeof(cthulhu_t));
	if (new == NULL)
		return (NULL);
	CthulhuInitializer(new);
	printf("----\n");
	printf("Building %s\n", new->m_name);
	return (new);
}

void	PrintPower(cthulhu_t *this)
{
	printf("Power => %d\n", this->m_power);
}

void	Attack(cthulhu_t *this)
{
	if (this->m_power >= 42)
	{
		printf("%s attacks and destroys the city\n", this->m_name);
		this->m_power -= 42;
	}
	else
	{
		printf("%s can't attack, he doesn't have enough power\n",
		 this->m_name);
	}
}

void	Sleeping(cthulhu_t *this)
{
	this->m_power += 42000;
	printf("%s sleeps\n", this->m_name);
}

static	void	KoalaInitializer(koala_t *this, char *_name,
	 char _isALegend)
{
	CthulhuInitializer(&this->m_parent);
	printf("Building %s\n", this->m_parent.m_name);
	this->m_parent.m_name = malloc(sizeof(char) * strlen(_name));
	this->m_parent.m_name = strdup(_name);
	printf("Building %s\n", this->m_parent.m_name);
	if (_isALegend > 0)
		this->m_parent.m_power = 42;
	else
		this->m_parent.m_power = 0;
}

koala_t	*NewKoala(char *name, char _isALegend)
{
	koala_t *new;

	printf("----\n");
	new = malloc(sizeof(koala_t));
	if (new == NULL)
		return (NULL);
	KoalaInitializer(new, name, _isALegend);
	return (new);
}

void	Eat(koala_t *this)
{
	this->m_parent.m_power += 42;
	printf("%s eats\n", this->m_parent.m_name);
}
