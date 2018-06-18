/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SGame.cpp
*/


#include <Component/Game/CTimeScd.hpp>
#include <Component/Game/CGameStatus.hpp>
#include "SGame.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <time.h>
#endif // defined(_WIN32) || defined(_WIN64)


static ECS::Entity findPlayer(ECS::Entity team) {
	auto PlayerIt = ECS::MComponent<CKeyMap>::getAll().begin();
	while (PlayerIt != ECS::MComponent<CKeyMap>::getAll().end()) {
		if (ECS::MComponent<CTeam>::get(PlayerIt->first)->team == team)
			return PlayerIt->first;
		std::advance(PlayerIt, 1);
	}
	return (0);
}

void SGame::init() {
	ECS::MComponent<CMesh>::create(ECS::MEntity::create(), CMesh());
}

void SGame::handleEvents() {
	irr::SEvent::SKeyInput event;

	while (ECS::MEvent<EKeyInputDown, irr::SEvent::SKeyInput>::pop(event)) {
		ECS::Entity curTeam = ECS::MComponent<CTurn>
		::getAll().begin()->second.currentTeam;
		ECS::Entity player = findPlayer(curTeam);

		if (player) {
			if (!ECS::MComponent<CKeyMap>::get(player))
				return;
			auto KeyMap = ECS::MComponent<CKeyMap>::get(player)
				->KeyMap;
			if (event.Key == KeyMap.at("switchWeapon"))
				this->switchWeapon(curTeam);
		}
	}
}

static void clean_munition()
{
	if (ECS::MComponent<CMuntion>::getAll().empty())
		return;
	for (auto it = ECS::MComponent<CMuntion>::getAll().begin();
	     it != ECS::MComponent<CMuntion>::getAll().end();
	     std::advance(it, 1)) {
		if (it->second.node)
			it->second.node = nullptr;
	}
	ECS::MComponent<CSceneNode>::getAll().begin()
		->second.munitionNode->removeAll();
}

void SGame::update(ECS::DeltaTime delta) {
	auto nbTeam = ECS::MComponent<CInventory>::getAll().size();
	if (nbTeam < 2)
		return;

	auto &status = ECS::MComponent<CGameStatus>::getAll().begin()->second;
	auto &timeList = ECS::MComponent<CTimeScd>::getAll();
	CTimeScd *timeGame = nullptr;

	for (auto it = timeList.begin(); it != timeList.end();
	     std::advance(it, 1))
		if (it->second.id == id_time::TIME_GAME)
			timeGame = &(it->second);
	if (!timeGame)
		return;
	if (status.start) {
		timeGame->last = std::time(nullptr);
		timeGame->waiting = std::time(nullptr) + 6;
		status.start = false;
	}
	if (std::time(nullptr) - timeGame->last > 3)
		timeGame->waiting += std::time(nullptr) - timeGame->last;

	if (!status.game && timeGame->waiting < std::time(nullptr)) {
		status.degat = true;
		status.wait = false;
		status.game = true;
		timeGame->waiting = std::time(nullptr) + 30;
	}
	if (status.game && timeGame->waiting < std::time(nullptr)) {
		clean_weapon();
		//try kill worm and team
		clean_munition();
		clean_weapon();
		ECS::MComponent<CTurn>::getAll().begin()->second.next();
		timeGame->waiting = std::time(nullptr) + 30;
		status.wait = false;
	}
	if (!status.wait) {
		ECS::Entity curTeam = ECS::MComponent<CTurn>
		::getAll().begin()->second.currentTeam;
		ECS::Entity player = findPlayer(curTeam);

		if (player)
			playerGestion(player);
		else
			aiGestion(curTeam);
	}
	timeGame->last = std::time(nullptr);
}

void SGame::postUpdate(ECS::DeltaTime delta) {
}

void SGame::preUpdate(ECS::DeltaTime delta) {
}

void SGame::move(ECS::Entity player, int type) {
	auto curWorm = ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.find(player);

	if (ECS::MComponent<CMap>::getAll().empty())
		return;
	auto &map = ECS::MComponent<CMap>::getAll().begin()->second._map;
	if (curWorm == ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.end())
		return;

	auto pos = ECS::MComponent<CPos>::get(curWorm->second);
	if (!pos)
		return;
	auto rot = ECS::MComponent<CRotation>::get(curWorm->second);
	rot->dir = type < 0 ? 200 : 0;
	if (type < 0) {
		if (map.find(
			((int) (pos->x + 11) - (int) (pos->x + 11) % 10) *
			10 + ((int) pos->y) / 10) == map.end() &&
		    map.find(
			    ((int) (pos->x + 11) - (int) (pos->x + 11) % 10) *
			    10 + ((int) pos->y + 9) / 10) == map.end())
			pos->x += 1;
	} else {
		if (map.find(
			((int) (pos->x - 1) - (int) (pos->x - 1) % 10) *
			10 + ((int) pos->y) / 9) == map.end() &&
		    map.find(
			    ((int) (pos->x - 1) - (int) (pos->x - 1) % 10) *
			    10 + ((int) pos->y + 9) / 10) == map.end())
			pos->x -= 1;
	}
}

void SGame::shoot(ECS::Entity player) {

	auto curWorm = ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.find(player);

	if (curWorm == ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.end())
		return;
	auto pos = ECS::MComponent<CPos>::get(curWorm->second);
	auto weapon = ECS::MComponent<CWeapon>::get(curWorm->second);
	auto rot = ECS::MComponent<CRotation>::get(curWorm->second);

	if (weapon->weapon == Eweapon::NONE)
		return;
	auto &status = ECS::MComponent<CGameStatus>::getAll().begin()->second;
	auto &timeList = ECS::MComponent<CTimeScd>::getAll();
	CTimeScd *timeGame = nullptr;

	for (auto it = timeList.begin(); it != timeList.end();
	     std::advance(it, 1))
		if (it->second.id == id_time::TIME_GAME)
			timeGame = &(it->second);
	if (!timeGame)
		return;

	timeGame->waiting = std::time(nullptr) + 8;
	status.wait = true;


	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto smgr = dev->getSceneManager();
	auto meshs = ECS::MComponent<CMesh>::getAll().begin()->second;
	irr::scene::IAnimatedMeshSceneNode *node;
	int type = 0;
	int texture = 0;
	if (weapon->weapon == Eweapon::BAZOOKA) {
		type = id_mesh::MESH_ROCKET;
		texture = id_mesh_texture::TEXTURE_ROCKET;
	} else if (weapon->weapon == Eweapon::GRENADE) {
		type = id_mesh::MESH_BOMB;
		texture = id_mesh_texture::TEXTURE_BOMB;
	} else if (weapon->weapon == Eweapon::SKY_STRIKER) {
		type = id_mesh::MESH_BOMB;
		texture = id_mesh_texture::TEXTURE_BOMB;
	}

	if (Eweapon::SKY_STRIKER != weapon->weapon) {
		node = smgr->addAnimatedMeshSceneNode(meshs.meshMap.at(type),
				ECS::MComponent<CSceneNode>::
				        getAll().begin()->second.munitionNode,
				-1, irr::core::vector3df(
				pos->x, pos->y + 10, 51.0f),
				 irr::core::vector3df(
					      -weapon->node->getRotation().X,
					      weapon->node->getRotation().Y,
					      weapon->node->getRotation().Z),
						      irr::core::vector3df(10,
									   10,
									   10));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMaterialTexture(0, meshs.meshTexture.at(texture));
		int dir = rot->dir > 100 ? 1 : -1;
		ECS::MComponent<CMuntion>::create(ECS::MEntity::create(),
						  CMuntion(
							  (int) pos->x,
							  (int) pos->y + 10,
							  rot->aim,
							  dir,
							  weapon->weapon,
							  node
						  ));
		return;
	}
	node = smgr->addAnimatedMeshSceneNode(
		meshs.meshMap.at(type),
		ECS::MComponent<CSceneNode>::
		getAll().begin()->second.munitionNode,
		-1, irr::core::vector3df(rand() % 450 + 25, 270, 51.0f),
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(10, 10, 10));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, meshs.meshTexture.at(texture));
	int dir = rot->dir > 100 ? 1 : -1;
	ECS::MComponent<CMuntion>
	        ::create(ECS::MEntity::create(), CMuntion(
	        	(int) pos->x,
			(int) pos->y + 10,
			rot->aim,
			dir,
			weapon->weapon,
			node
	));
	node = smgr->addAnimatedMeshSceneNode(
		meshs.meshMap.at(type),
		ECS::MComponent<CSceneNode>::
		getAll().begin()->second.munitionNode,
		-1, irr::core::vector3df(rand() % 450 + 25, 270, 51.0f),
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(10, 10, 10));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, meshs.meshTexture.at(texture));
	ECS::MComponent<CMuntion>
	::create(ECS::MEntity::create(), CMuntion(
		(int) pos->x,
		(int) pos->y + 10,
		rot->aim,
		dir,
		weapon->weapon,
		node
	));
	node = smgr->addAnimatedMeshSceneNode(
		meshs.meshMap.at(type),
		ECS::MComponent<CSceneNode>::
		getAll().begin()->second.munitionNode,
		-1, irr::core::vector3df(rand() % 450 + 25, 270, 51.0f),
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(10, 10, 10));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, meshs.meshTexture.at(texture));
	ECS::MComponent<CMuntion>
	::create(ECS::MEntity::create(), CMuntion(
		(int) pos->x,
		(int) pos->y + 10,
		rot->aim,
		dir,
		weapon->weapon,
		node
	));
}

void SGame::aimDir(ECS::Entity player, int type) {
	auto curWorm = ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.find(player);

	if (curWorm == ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.end())
		return;

	auto rot = ECS::MComponent<CRotation>::get(curWorm->second);
	if (rot) {
		rot->aim += type < 0 ? -4 : 4;
		if (rot->aim > 50)
			rot->aim = 50;
		if (rot->aim < -50)
			rot->aim = -50;
	}
}

void SGame::switchWeapon(ECS::Entity player) {
	auto curWorm = ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.find(player);

	if (curWorm == ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.end())
		return;
	switch_worm_weapon(curWorm->second);
}

void SGame::jump(ECS::Entity player) {
	auto curWorm = ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.find(player);

	if (curWorm == ECS::MComponent<CTurn>
	::getAll().begin()->second.currentWorm.end())
		return;
	auto jump = ECS::MComponent<CJump>::get(curWorm->second);
	auto pos = ECS::MComponent<CPos>::get(curWorm->second);
	if (!jump || !pos)
		return;
	if (ECS::MComponent<CMap>::getAll().empty())
		return;
	auto map = ECS::MComponent<CMap>::getAll().begin()->second._map;
	if (jump->jump == 0 && !(map.find(
		((int) pos->x - (int) pos->x % 10) *
		10 + ((int) pos->y - 1) / 10) == map.end() &&
				 map.find(((int) pos->x + 5 -
					   (int) (pos->x + 5) % 10) * 10 +
					  ((int) pos->y - 1) / 10) ==
				 map.end()))
		jump->jump = 22;
}

void SGame::playerGestion(ECS::Entity player) {
	if (!ECS::MComponent<CKeyMap>::get(player))
		return;
	auto KeyMap = ECS::MComponent<CKeyMap>::get(player)->KeyMap;
	auto KeyIsDown = ECS::MComponent<CKeyIsDown>::getAll().begin()->second;
	ECS::Entity team = ECS::MComponent<CTeam>::get(player)->team;

	if (KeyIsDown.KeyIsDown[KeyMap.at("left")])
		this->move(team, -1);
	if (KeyIsDown.KeyIsDown[KeyMap.at("right")])
		this->move(team, 1);
	if (KeyIsDown.KeyIsDown[KeyMap.at("aimUp")])
		this->aimDir(team, -1);
	if (KeyIsDown.KeyIsDown[KeyMap.at("aimDown")])
		this->aimDir(team, 1);
	if (KeyIsDown.KeyIsDown[KeyMap.at("shoot")])
		this->shoot(team);
	if (KeyIsDown.KeyIsDown[KeyMap.at("jump")])
		this->jump(team);
}

void SGame::aiGestion(ECS::Entity team) {
	std::cout << "\n\n--------\tDEBUG AI START HERE\t--------\n\n"
		  << std::endl;
	AiCore ai;
	ai.mainAi(team);
	float movement = ai.moveAI(team);
	move(team, movement);
	if (movement != 0)
		jump(team);
	if (movement == 0) {
		switchWeapon(team);
		shoot(team);
		switchWeapon(team);
		shoot(team);
	}
	std::cout << "\n\n--------\tDEBUG AI END HERE\t--------\n\n"
		  << std::endl;
}
