/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** ETeam
*/

#ifndef ETEAM_HPP_
	#define ETEAM_HPP_

#include <irrlicht.h>
#include "ECS/Entity/MEntity.hpp"
#include "ECS/Component/MComponent.hpp"
#include "Component/Game/CColor.hpp"
#include "Component/Game/CInventory.hpp"
#include "Component/Game/CKeyMap.hpp"
#include "Component/Game/CTeam.hpp"
#include "Component/Game/CWormList.hpp"

ECS::Entity createTeam();
void removeTeam(ECS::Entity);

#endif /* !ETEAM_HPP_ */
