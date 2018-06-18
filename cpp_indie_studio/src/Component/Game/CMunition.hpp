/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CMunition.hpp
*/


#ifndef INDIESTUDIO_CMUNITION_HPP
#define INDIESTUDIO_CMUNITION_HPP

#include <ctime>
#include "irrlicht.h"

class CMuntion {
public:
	CMuntion() = default;
	CMuntion(int x, int y, float a, int d, int t,
		 irr::scene::IAnimatedMeshSceneNode* n)
		: xOrigin(x), yOrigin(y), aim(a), dir(d), type(t),
		  t_launch(clock()), node(n) {};
	~CMuntion() = default;
	int xOrigin;
	int yOrigin;
	float aim;
	int dir;
	int type;
	clock_t t_launch;
	irr::scene::IAnimatedMeshSceneNode* node;
};

#endif //INDIESTUDIO_CMUNITION_HPP
