/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapCreate.cpp
*/

#include "CMap.hpp"
#include <map>
// random sur un pattern
// check si on peut caser le patern
// case

void addToCube(irr::scene::ISceneManager* sceneManager,
		irr::video::IVideoDriver* driver,
	       std::map<int, irr::scene::IMeshSceneNode*> &map,
		int i, double first, double second, bool texture)
{
	irr::scene::IMeshSceneNode *node;
	node = sceneManager->addCubeSceneNode(10.0f,
		ECS::MComponent<CSceneNode>::getAll().begin()->second.mapNode,
			-1, irr::core::vector3df(((int)first - (int)first % 10),
					 (int)second - (int)second % 10,
					 50.0f));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
	if (texture)
		node->setMaterialTexture(1, driver->getTexture("media/grasse.jpg"));
	else
		node->setMaterialTexture(0, driver->getTexture("media/black.png"));
	node->setMaterialType(irr::video::EMT_DETAIL_MAP);
	map.emplace(((int)first - (int)first % 10) * 10 + (int)second / 10, node);
}

void createMap(irr::scene::ISceneManager* sceneManager,
	       irr::video::IVideoDriver* driver,
	       std::map<int, irr::scene::IMeshSceneNode*> &map,
	       int nbr_cube)
{
	double first = 0.0f;
	double second = -5.0f;
	int	tranche = 50;
	std::map<int, bool> pos;

	for (int i = 0; i < nbr_cube; i++) {
		if (i <= tranche + 1)
			fillBotom(&first, &second);
		else if (i > tranche && i <= tranche * 2)
			fillRight(&first, &second);
		else if (i > tranche * 2 && i <= tranche * 3)
			fillLeft(&first, &second);
		else if (i > tranche * 3)
			fillBloc(&first, &second);
		if (pos.find(((int)first - (int)first % 10)* 1000 +
			     ((int)second - (int)second % 10)) == pos.end()) {
			addToCube(sceneManager, driver, map, i,
				  (double) ((int) first - (int) first % 10),
				  (double) ((int) second - (int) second % 10),
				  i > tranche * 3);
			pos.emplace((((int)first - (int)first % 10)* 1000 +
				     ((int)second - (int)second % 10)), true);
		}
	}
}
