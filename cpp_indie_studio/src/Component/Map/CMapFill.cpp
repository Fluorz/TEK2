/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapFill.cpp
*/

#include "CMap.hpp"

double frand_a_b(double a, double b)
{
	return ((rand() / (double) RAND_MAX) * (b - a) + a);
}

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}

void 	fillBloc(double *first, double *second)
{
	static	int i = 0;
	static int to_rand = 0;

	if (i > 4)
	{
		to_rand = rand_a_b(0, 2);
		i = 0;
	}
	if (to_rand == 0)
	{
		fillBloc4(first, second);
	}
	else
	{
		fillBlocS(first, second);
	}
	i++;
}

void 	fillBloc4(double *first, double *second)
{
	static	int i = 0;
	double	f_x = 0.0f;
	double	f_y = 0.0f;

	if (i > 4)
		i = 0;
	if (i == 0)
	{
		//Si premiere fois, calculé le premier x,y
		f_x = frand_a_b(100, 400);
		f_y = frand_a_b(10, 270);
		*first = f_x;
		*second = f_y;
	}
	else if (i < 4)
		*first = *first + 10.0f;
	i++;
}

void 	fillBlocS(double *first, double *second)
{
	static	int i = 0;
	double	f_x = 0.0f;
	double	f_y = 0.0f;

	if (i > 6)
		i = 0;
	if (i == 0)
	{
		//Si premiere fois, calculé le premier x,y
		f_x = frand_a_b(200, 400);
		f_y = frand_a_b(10, 300);
		*first = f_x;
		*second = f_y;
	}
	if (i < 6)
	{
		if (i == 3 || i == 4)
		{
			*second = *second + 10.0f;
		}
		else
		{
			*first = *first + 10.0f;
		}
		i++;
	}
}

void	fillBotom(double *first, double *second)
{
	*first += 10.0f;
}

void	fillRight(double *first, double *second)
{
	static double before = 0.0f;
	static	int i = 0;
	static bool pass = false;
	static int m_construct = 0;

	if (i == 0)
	{
		*first = 10.0f;
		*second = 0.0f;
	}
	else if (i >= 4 && i < 6)
	{
		pass = true;
		before = *second;
		*first += 10.0f;
	}
	else if (i >= 10 && i < 25)
	{

		if (m_construct == 0)
		{
			pass = true;
			before = *second;
			m_construct++;
		}
		if (i >= 10 && i < 15)
		{
			*first += 10.0f;
		}
		else if (i >= 15 && i <= 20)
		{
			*second += 10.0f;
		}
		else
		{
			*first += 10.0f;
		}
	}
	else if (i > 35 && i < 40)
	{
		*first += 10.0f;
	}
	else {
		if (pass == true)
		{
			*second = before;
			pass = false;
		}
		*first = 10.0f;
		*second += 10.0f;
	}
	i++;
	if (i == 50)
	{
		i = 0;
		before = 0.0f;
		pass = false;
		m_construct = 0;
	}
}

void	fillLeft(double *first, double *second)
{
	static double before = 0.0f;
	static	int i = 0;
	static bool pass = false;
	static int m_construct = 0;

	if (i == 0)
	{
		*first = 510.0f;
		*second = 0.0f;
	}
	else if (i >= 4 && i < 6)
	{
		pass = true;
		before = *second;
		*first -= 10.0f;
	}
	else if (i >= 10 && i < 25)
	{

		if (m_construct == 0)
		{
			pass = true;
			before = *second;
			m_construct++;
		}
		if (i >= 10 && i < 15)
		{
			*first -= 10.0f;
		}
		else if (i >= 15 && i <= 20)
		{
			*second += 10.0f;
		}
		else
		{
			*first -= 10.0f;
		}
	}
	else if (i > 35 && i < 40)
	{
		*first -= 10.0f;
	}
	else {
		if (pass == true)
		{
			*second = before;
			pass = false;
		}
		*first = 510.0f;
		*second += 10.0f;
	}
	i++;
	if (i == 50)
	{
		i = 0;
		before = 0.0f;
		pass = false;
		m_construct = 0;
	}
}
