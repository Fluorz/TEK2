/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CWeapon.cpp
*/

#include "CWeapon.hpp"

/*
	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto smgr = dev->getSceneManager();
	auto meshs = ECS::MComponent<CMesh>::getAll().begin()->second;
	irr::scene::IAnimatedMeshSceneNode* node;
	node = smgr->addAnimatedMeshSceneNode(meshs.meshMap.at(MESH_PENGUIN),
		ECS::MComponent<CSceneNode>::getAll().begin()->second.meshNode,
				-1, irr::core::vector3df(x, y, 51.0f),
				irr::core::vector3df(0, 0, 0),
				irr::core::vector3df(4, 4, 4));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, meshs.meshTexture.at(TEXTURE_PENGUIN));
	node->setScale(irr::core::vector3df(8, 5, 5));
 */

void switch_worm_weapon(ECS::Entity curWorm)
{
	if (!ECS::MComponent<CWeapon>::get(curWorm))
		return;
	auto pos = ECS::MComponent<CPos>::get(curWorm);
	if (!pos)
		return;
	auto weapon = ECS::MComponent<CWeapon>::get(curWorm);
	if (weapon->node)
		weapon->node = nullptr;
	clean_weapon();
	weapon->weapon++;
	if (weapon->weapon == Eweapon::LAST) {
		weapon->weapon = Eweapon::NONE;
		return;
	}

	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto smgr = dev->getSceneManager();
	auto meshs = ECS::MComponent<CMesh>::getAll().begin()->second;

	int mesh = -1;
	int texture = -1;

	switch (weapon->weapon) {
		case Eweapon::BAZOOKA:
			mesh = id_mesh::MESH_BAZOOKA;
			texture = id_mesh_texture::TEXTURE_BAZOOKA;
			break;
		case Eweapon::GRENADE:
			mesh = id_mesh::MESH_BOMB_LAUNCHER;
			texture = id_mesh_texture::TEXTURE_BOMB_LAUNCHER;
			break;
	}
	if (mesh == -1 || texture == -1)
		return;

	weapon->node = smgr->addAnimatedMeshSceneNode(meshs.meshMap.at(mesh),
		ECS::MComponent<CSceneNode>::getAll().begin()->second.weaponNode,
		-1, irr::core::vector3df(pos->x, pos->y + 5, 54.0f),
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(7, 5, 5));

	weapon->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	weapon->node->setMaterialTexture(0, meshs.meshTexture.at(texture));
}

void clean_weapon()
{
	if (ECS::MComponent<CWeapon>::getAll().empty())
		return;
	for (auto it = ECS::MComponent<CWeapon>::getAll().begin();
		it != ECS::MComponent<CWeapon>::getAll().end();
		std::advance(it, 1)) {
		if (it->second.node)
			it->second.node = nullptr;
	}
	ECS::MComponent<CSceneNode>::getAll().begin()
		->second.weaponNode->removeAll();
}
