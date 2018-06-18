/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CSceneNode.hpp
*/


#ifndef INDIESTUDIO_CSCENENODE_HPP
#define INDIESTUDIO_CSCENENODE_HPP

#include "irrlicht.h"
#include "Component/Irrlicht/irrlichtComponent.hpp"

enum is_scene_node {
	SCENE_NODE_MESH,
	SCENE_NODE_MAP,
	SCENE_NODE_MESH_WEAPON,
	SCENE_NODE_MESH_MUNITION
};

class CSceneNode {
public:
	CSceneNode();
	~CSceneNode();
	irr::scene::ISceneNode* meshNode;
	irr::scene::ISceneNode* mapNode;
	irr::scene::ISceneNode* weaponNode;
	irr::scene::ISceneNode* munitionNode;

};


#endif /* INDIESTUDIO_CSCENENODE_HPP */
