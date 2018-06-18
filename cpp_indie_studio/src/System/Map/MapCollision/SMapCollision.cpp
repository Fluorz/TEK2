/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        Collision.cpp
*/

#include "SMapCollision.hpp"

bool	checkPosition(std::vector<irr::scene::IMeshSceneNode*> &map,
		irr::scene::IAnimatedMeshSceneNode* mesh, const char *string)
{
	int i = 0;
	while (i != 200)
	{
		irr::core::vector3df d = mesh->getPosition();
		irr::core::vector3df s = map[i]->getPosition();
		if (strcmp(string, "up") == 0)
		{
			if (d.X == s. X && d.Y <= s.Y)
			{
				printf("--Colision---\n");
				printf("Up\n");
				printf("X Pinguin = %f\n", d.X);
				printf("Y Pinguin = %f\n", d.Y);
				printf("X Box = %f\n", s.X);
				printf("Y Box = %f\n", s.Y);
				return (false);
			}
		}
		else if (strcmp(string, "down") == 0)
		{
				if (d.X - i == s.X && d.Y <= s.Y)
				{
					printf("--Colision---\n");
					printf("Down\n");
					printf("X Pinguin = %f\n", d.X);
					printf("Y Pinguin = %f\n", d.Y);
					printf("X Box = %f\n", s.X);
					printf("Y Box = %f\n", s.Y);
					return (false);
				}
		}
		else if (strcmp(string, "left") == 0)
		{
			for (int i = 0; i < 5; i++) {
				printf("--Colision---\n");
				printf("Left\n");
				printf("X Pinguin = %f\n", d.X);
				printf("Y Pinguin = %f\n", d.Y);
				printf("X Box = %f\n", s.X);
				printf("Y Box = %f\n", s.Y);
				if (d.X - i == s.X && d.Y == s.Y)
				{
					return (false);
				}
			}
		}
		else if (strcmp(string, "right") == 0)
		{
			if (d.X == s.X + 10 && d.Y == s.Y)
			{
				printf("--Colision---\n");
				printf("Right\n");
				printf("X Pinguin = %f\n", d.X);
				printf("Y Pinguin = %f\n", d.Y);
				printf("X Box = %f\n", s.X);
				printf("Y Box = %f\n", s.Y);
				return (false);
			}
		}
		i++;
	}
	return (true);
}
