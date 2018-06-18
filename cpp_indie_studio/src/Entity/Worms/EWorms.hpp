/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** EWorms
*/

#ifndef EWORMS_HPP_
	#define EWORMS_HPP_

#include "ECS/Entity/MEntity.hpp"
#include <irrlicht.h>
#include "ECS/Component/MComponent.hpp"
#include "Component/Game/CWeapon.hpp"
#include "Component/Graphical/CSkin.hpp"
#include "Component/Game/CLife.hpp"
#include "Component/Game/CTeam.hpp"
#include "Component/Game/CName.hpp"
#include "Component/Physic/CPos.hpp"
#include "Component/Physic/CFall.hpp"
#include "Component/Physic/CMovement.hpp"
#include "Component/Physic/CRotation.hpp"
#include "Component/Physic/CJump.hpp"

void wormDamage(ECS::Entity worm, int dmg);
ECS::Entity createWorms(ECS::Entity team);
void removeWorms(ECS::Entity);

#endif /* !EWORMS_HPP_ */
