/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CMesh.cpp
*/

#include "CMesh.hpp"

CMesh::CMesh()
{
	if (ECS::MComponent<CIrrMain>::getAll().empty())
		return;
	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	auto smgr = dev->getSceneManager();

	meshMap.emplace(MESH_PENGUIN, smgr->getMesh("media/pinguin_soldier.ms3d"));
	meshMap.emplace(MESH_BAZOOKA, smgr->getMesh("media/bazooka.ms3d"));
	meshMap.emplace(MESH_BOMB_LAUNCHER, smgr->getMesh("media/bomb_launcher.ms3d"));
	meshMap.emplace(MESH_BOMB, smgr->getMesh("media/bomb.ms3d"));
	meshMap.emplace(MESH_PALM, smgr->getMesh("media/palm.ms3d"));
	meshMap.emplace(MESH_ROCKET, smgr->getMesh("media/rocket.ms3d"));

	meshTexture.emplace(TEXTURE_PENGUIN, driv->getTexture("media/soldier_texture.png"));
	meshTexture.emplace(TEXTURE_BAZOOKA, driv->getTexture("media/bazooka_texture.png"));
	meshTexture.emplace(TEXTURE_BOMB_LAUNCHER, driv->getTexture("media/launcher_texture.png"));
	meshTexture.emplace(TEXTURE_BOMB, driv->getTexture("media/bomb_texture.png"));
	meshTexture.emplace(TEXTURE_PALM, driv->getTexture("media/palm_texture.png"));
	meshTexture.emplace(TEXTURE_ROCKET, driv->getTexture("media/rocket_texture.png"));
}

CMesh::~CMesh()
{

}
