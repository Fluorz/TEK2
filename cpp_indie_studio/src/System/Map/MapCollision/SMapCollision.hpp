/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapCollision.hpp
*/

#include <string>
#include <vector>
#include "irrlicht.h"

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"


bool	checkPosition(std::vector<irr::scene::IMeshSceneNode*> &map,
	irr::scene::IAnimatedMeshSceneNode* mesh, const char *string);
