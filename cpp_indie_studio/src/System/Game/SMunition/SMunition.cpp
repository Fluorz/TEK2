/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMunition.cpp
*/


#include "SMunition.hpp"

static void destructMap(int x, int y, int range,
			std::map<int, irr::scene::IMeshSceneNode *> &map) {
	for (int x1 = x - range; x1 < x + range; x1++) {
		for (int y1 = y - range; y1 < y + range; y1++) {
			if (map.find((x1 - x1 % 10) * 10 + y1 / 10) !=
			    map.end()) {
				auto it = map.find(
					(x1 - x1 % 10) * 10 + y1 / 10);
				it->second->setPosition(irr::core::vector3df(
					it->second->getPosition().X - 600,
					it->second->getPosition().Y - 600,
					it->second->getPosition().Z));
				map.erase((x1 - x1 % 10) * 10 + y1 / 10);
			}
		}
	}
}

static void destroyMun(CMuntion &mun, ECS::Entity id) {
	mun.node->setPosition(irr::core::vector3df(-100, -100, 51));
	ECS::MComponent<CMuntion>::remove(id);
}

static void wormsDamage(int x, int y, int range) {
	auto &PosList = ECS::MComponent<CPos>::getAll();
	for (auto it = PosList.begin(); it != PosList.end();
	     std::advance(it, 1)) {
		if (it->second.x < x + range && it->second.x > x - range &&
		    it->second.y < y + range && it->second.y > y - range) {
			float distX =
				x - it->second.x < 0 ? it->second.x - x : x -
									  it->second.x;
			float distY =
				y - it->second.y < 0 ? it->second.y - y : y -
									  it->second.y;
			float fDist = distX < distY ? distX : distY;
			wormDamage(it->first,
				   (int) (80 * ((float) (range - fDist) /
						float(range))));
		}
	}
}

static void munAdvance(CMuntion &mun, ECS::Entity id) {
	auto x = mun.node->getPosition().X;
	auto y = mun.node->getPosition().Y;
	float a = mun.aim / (float) 50.0;
	float b = mun.yOrigin - mun.xOrigin * a * -mun.dir;

	switch (mun.type) {
		case Eweapon::GRENADE:
			mun.node->setPosition(
				irr::core::vector3df(x + 2 * mun.dir,
						     a * -mun.dir *
						     (x + 2 * mun.dir) + b,
						     51));
			break;
		case Eweapon::BAZOOKA:
			mun.node->setPosition(
				irr::core::vector3df(x + 2 * mun.dir,
						     a * -mun.dir *
						     (x + 2 * mun.dir) + b,
						     51));
			break;
		case Eweapon::SKY_STRIKER:
			mun.node->setPosition(
				irr::core::vector3df(x, y - 2, 51));
			break;
	}
}


void SMunition::update(ECS::DeltaTime delta) {
	auto &MunList = ECS::MComponent<CMuntion>::getAll();
	auto &map = ECS::MComponent<CMap>::getAll().begin()->second._map;

	for (auto it = MunList.begin(); it != MunList.end();
	     std::advance(it, 1)) {
		if (!it->second.node)
			continue;
		auto x = it->second.node->getPosition().X;
		auto y = it->second.node->getPosition().Y;
		if (map.find(((int) x - (int) x % 10) * 10 + (int) y / 10) !=
		    map.end() ||
		    map.find(((int) x - (int) x % 10) * 10 +
			     (int) (y + 10) / 10) != map.end()) {
			destructMap((int) x, (int) y, 20, map);
			destroyMun(it->second, it->first);
			wormsDamage((int) x, (int) y, 30);
			return;
		} else if (x < -20 || x > 520 || y < -20 || y > 280) {
			destroyMun(it->second, it->first);
			return;
		} else {
			munAdvance(it->second, it->first);
		}
	}
}
