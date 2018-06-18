/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        main.hpp
*/

#ifndef _HEADER_
# define _HEADER_

#include <string>
#include <vector>
#include "irrlicht.h"
#include "Component/Graphical/CSceneNode.hpp"

class CMap
{
public:
	CMap() = default;
	CMap(std::map<int, irr::scene::IMeshSceneNode*> &m, int cube)
		: _map(m), _cube(cube) {};
	// ~CMap();
	std::map<int, irr::scene::IMeshSceneNode*> _map;
	int _cube;
};

void createMap(irr::scene::ISceneManager* sceneManager,
	       irr::video::IVideoDriver* driver,
	       std::map<int, irr::scene::IMeshSceneNode*> &map,
	       int nbr_cube);

int	rand_a_b(int a, int b);
double frand_a_b(double a, double b);

void 	fillBloc4(double *first, double *second);
void 	fillBlocS(double *first, double *second);
void	fillMiddle(double *first, double *second);
void	fillLeft(double *first, double *second);
void	fillRight(double *first, double *second);
void	fillBotom(double *first, double *second);
void 	fillBloc(double *first, double *second);

#endif
