/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapDestruction.cpp
*/

#include "SMapDestruction.hpp"
// Trouver la coordonée
// Détruire le bloc le plus proche
// apploqué la range sur les bloc

bool	destructBloc(int x, int y, int range)
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	auto &map = ECS::MComponent<CMap>::getAll();
	if (DeviceContener.empty() || map.empty()) {
		printf("map empty\n");
		return (false);
	}
	auto &env = DeviceContener.begin()->second.env;
	auto &driver = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	irr::scene::ISceneManager* sceneManager =
		device->getSceneManager();
	auto &tmp = map.begin()->second._map;
	auto &cube = map.begin()->second._cube;

	int i = 0;
	while (tmp[i]) {
		irr::core::vector3df test = tmp[i]->getPosition();
		if ((int)test.X >= x - 10 && (int)test.X <= x + 10
		&& (int)test.Y >= y - 10 && (int)test.Y <= y + 10) {
			int y = 0;
			while (y != range) {
				tmp[i]->setPosition(irr::core::vector3df(
					-100,
					-100,
					0
				));
				i++;
				y++;
			}
			return (true);
		}
		i++;
	}
}
