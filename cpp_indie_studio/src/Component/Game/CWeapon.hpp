/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CWeapon.hpp
*/


#ifndef INDIESTUDIO_CWEAPON_HPP
#define INDIESTUDIO_CWEAPON_HPP

enum Eweapon {
	NONE,
	SKY_STRIKER,
	BAZOOKA,
	GRENADE,
	LAST
};

#include "irrlicht.h"
#include "ECS/Component/MComponent.hpp"
#include "Component/Graphical/CSceneNode.hpp"

class CWeapon {
public:
	CWeapon() : weapon(Eweapon::NONE), node(nullptr) {};
	CWeapon(Eweapon weap, irr::scene::IAnimatedMeshSceneNode *n = nullptr)
		: weapon(weap), node(n) {};
	~CWeapon() = default;
	int weapon;
	irr::scene::IAnimatedMeshSceneNode* node;
};

void switch_worm_weapon(ECS::Entity curWorm);
void clean_weapon();

#endif /* INDIESTUDIO_CWEAPON_HPP */
