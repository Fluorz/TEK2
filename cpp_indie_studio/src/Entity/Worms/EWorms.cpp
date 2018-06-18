/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** EWorms
*/

#include "EWorms.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Component/Graphical/CMesh.hpp"
#include <vector>
#include <Component/Game/CGameStatus.hpp>

std::vector<std::string> nameList;

std::string select_random() {
	if (nameList.empty()) {
		nameList.emplace_back("Arlen");
		nameList.emplace_back("Fausto");
		nameList.emplace_back("Carmen");
		nameList.emplace_back("Pablo");
		nameList.emplace_back("Marc");
		nameList.emplace_back("Lane");
		nameList.emplace_back("Anibal");
		nameList.emplace_back("Jean");
		nameList.emplace_back("Antwan");
		nameList.emplace_back("Zachary");
		nameList.emplace_back("Blaine");
		nameList.emplace_back("Josiah");
		nameList.emplace_back("Cesar");
		nameList.emplace_back("Esteban");
		nameList.emplace_back("Ramon");
		nameList.emplace_back("Hoyt");
		nameList.emplace_back("Damon");
		nameList.emplace_back("Son");
		nameList.emplace_back("Dave");
		nameList.emplace_back("Adam");
		nameList.emplace_back("Refugio");
		nameList.emplace_back("Ollie");
		nameList.emplace_back("Leandro");
		nameList.emplace_back("Collin");
		nameList.emplace_back("Justin");
		nameList.emplace_back("Leo");
		nameList.emplace_back("Blake");
		nameList.emplace_back("Huey");
		nameList.emplace_back("ESCANOR SAMA DA");
		nameList.emplace_back("Sammie");
		nameList.emplace_back("Curtis");
		nameList.emplace_back("Otis");
		nameList.emplace_back("Chris");
		nameList.emplace_back("Jamison");
		nameList.emplace_back("Harris");
		nameList.emplace_back("Lauren");
		nameList.emplace_back("Zachery");
		nameList.emplace_back("Carter");
		nameList.emplace_back("Waylon");
		nameList.emplace_back("Alvaro");
		nameList.emplace_back("Damian");
		nameList.emplace_back("Britt");
		nameList.emplace_back("Rene");
		nameList.emplace_back("Galen");
		nameList.emplace_back("Willard");
		nameList.emplace_back("Emerson");
		nameList.emplace_back("Jamar");
		nameList.emplace_back("Leif");
		nameList.emplace_back("Theo");
		nameList.emplace_back("Ethelene");
		nameList.emplace_back("Celia");
		nameList.emplace_back("Enola");
		nameList.emplace_back("Lynetta");
		nameList.emplace_back("Kittie");
		nameList.emplace_back("Vanda");
		nameList.emplace_back("Lashell");
		nameList.emplace_back("Anastacia");
		nameList.emplace_back("Krystal");
		nameList.emplace_back("Fairy");
		nameList.emplace_back("Debora");
		nameList.emplace_back("Charlena");
		nameList.emplace_back("Avelina");
		nameList.emplace_back("Anjanette");
		nameList.emplace_back("Sana");
		nameList.emplace_back("Eula");
		nameList.emplace_back("Ema");
		nameList.emplace_back("Edra");
		nameList.emplace_back("Ninfa");
		nameList.emplace_back("Whitley");
		nameList.emplace_back("Sharyl");
		nameList.emplace_back("Elayne");
		nameList.emplace_back("Kristie");
		nameList.emplace_back("Melvina");
		nameList.emplace_back("Marjory");
		nameList.emplace_back("Domenica");
		nameList.emplace_back("Ardis");
		nameList.emplace_back("Sheridan");
		nameList.emplace_back("Shavon");
		nameList.emplace_back("Sharlene");
		nameList.emplace_back("Maya");
		nameList.emplace_back("Lorriane");
		nameList.emplace_back("Carlotta");
		nameList.emplace_back("Kiana");
		nameList.emplace_back("Macie");
		nameList.emplace_back("Shenna");
		nameList.emplace_back("Solange");
		nameList.emplace_back("Alberta");
		nameList.emplace_back("Cindie");
		nameList.emplace_back("Myrtle");
		nameList.emplace_back("Genevie");
		nameList.emplace_back("Kati");
		nameList.emplace_back("Sook");
		nameList.emplace_back("Latrisha");
		nameList.emplace_back("Margeret");
		nameList.emplace_back("Isabell");
		nameList.emplace_back("Corina");
		nameList.emplace_back("Jaclyn");
		nameList.emplace_back("Angle");
		nameList.emplace_back("Janeth");
	}
	long it = (rand() % static_cast<int>(nameList.size()));
	return (nameList.at(static_cast<unsigned long>(it)));
}

static bool checkPos(float x, float y)
{
	if (ECS::MComponent<CMap>::getAll().empty())
		return false;
	auto map = ECS::MComponent<CMap>::getAll().begin()->second._map;
	int coo = ((int)x - (int)x % 10) * 10 + (int)y / 10;
	return map.find(coo) != map.end();
}

ECS::Entity createWorms(ECS::Entity team)
{
	auto worms = ECS::MEntity::create();
	std::string name = select_random();
	float x = rand() % 480 + 10;
	float y = rand() % 200 + 50;
	int i = 0;

	while (checkPos(x, y)) {
		x = rand() % 480 + 10;
		y = rand() % 200 + 50;
		if (i++ > 50) {
			std::cout << "abandon" << std::endl;
			break;
		}
	}

	if (ECS::MComponent<CIrrMain>::getAll().empty() ||
	    ECS::MComponent<CMesh>::getAll().empty())
		return 0;

	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto smgr = dev->getSceneManager();
	auto meshs = ECS::MComponent<CMesh>::getAll().begin()->second;
	irr::scene::IAnimatedMeshSceneNode* node;
	node = smgr->addAnimatedMeshSceneNode(meshs.meshMap.at(MESH_PENGUIN),
		ECS::MComponent<CSceneNode>::getAll().begin()->second.meshNode,
				-1, irr::core::vector3df(x, y, 51.0f),
				irr::core::vector3df(0, 200, 0),
				irr::core::vector3df(4, 4, 4));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialTexture(0, meshs.meshTexture.at(TEXTURE_PENGUIN));

	ECS::MComponent<CPos>::create(worms, CPos(x, y));
	ECS::MComponent<CWeapon>::create(worms, CWeapon());
	ECS::MComponent<CMovement>::create(worms, CMovement());
	ECS::MComponent<CLife>::create(worms, CLife(100));
	ECS::MComponent<CSkin>::create(worms, CSkin(node));
	ECS::MComponent<CFall>::create(worms, CFall());
	ECS::MComponent<CName>::create(worms, CName(name));
	ECS::MComponent<CTeam>::create(worms, CTeam(team));
	ECS::MComponent<CRotation>::create(worms, CRotation());
	ECS::MComponent<CJump>::create(worms, CJump());
	return worms;
}

void wormDamage(ECS::Entity worm, int dmg)
{
	if (ECS::MComponent<CGameStatus>::getAll().empty() ||
		!ECS::MComponent<CLife>::get(worm))
		return;
	auto &game = ECS::MComponent<CGameStatus>::getAll().begin()->second;
	auto life = ECS::MComponent<CLife>::get(worm);

	if (game.degat)
		life->life -= dmg;
	if (life->life < 0)
		life->life = 0;
}

void removeWorms(ECS::Entity worm)
{
	auto node = ECS::MComponent<CSkin>::get(worm)->node;
	node->setPosition(irr::core::vector3df(-100, -100, 51));
	ECS::MEntity::remove(worm);
}
