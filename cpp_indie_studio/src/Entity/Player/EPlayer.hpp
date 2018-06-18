/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** EPlayer.hpp
*/


#ifndef INDIESTUDIO_EPLAYER_HPP
#define INDIESTUDIO_EPLAYER_HPP

#include <irrlicht.h>
#include "ECS/Entity/MEntity.hpp"
#include "ECS/Component/MComponent.hpp"
#include "Component/Game/CKeyMap.hpp"
#include "Component/Game/CTeam.hpp"
#include "Component/Game/CKeyMapStatic.hpp"

ECS::Entity createPlayer();
void removePlayer(ECS::Entity);

#endif /* INDIESTUDIO_EPLAYER_HPP */
