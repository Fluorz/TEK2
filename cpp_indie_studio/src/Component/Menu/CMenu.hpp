/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CMenu.hpp
*/


#ifndef INDIESTUDIO_CMENU_HPP
#define INDIESTUDIO_CMENU_HPP

#include <irrlicht.h>
#include "Component/Id.hpp"

class CCheckBoxs {
public:
	CCheckBoxs() : player(id_gui::CHECK_BOX_1_PLAYER),
		       team(id_gui::CHECK_BOX_2_TEAM) {}
	~CCheckBoxs() = default;
	int player;
	int team;
};

class CLoading {
public:
	CLoading() : img(false) {};
	~CLoading() = default;
	bool img;
};

#endif /* INDIESTUDIO_CMENU_HPP */
