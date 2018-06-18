/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CSceneNode.cpp
*/


#include "CSceneNode.hpp"

CSceneNode::CSceneNode()
{
	if (ECS::MComponent<CIrrMain>::getAll().empty())
		return;
	auto smgr = ECS::MComponent<CIrrMain>::getAll().begin()
		->second.device->getSceneManager();

	mapNode = smgr->addEmptySceneNode(nullptr, SCENE_NODE_MAP);
	meshNode = smgr->addEmptySceneNode(nullptr, SCENE_NODE_MESH);
	weaponNode = smgr->addEmptySceneNode(nullptr, SCENE_NODE_MESH_WEAPON);
	munitionNode = smgr->addEmptySceneNode(nullptr, SCENE_NODE_MESH_MUNITION);
}

CSceneNode::~CSceneNode()
{

}
