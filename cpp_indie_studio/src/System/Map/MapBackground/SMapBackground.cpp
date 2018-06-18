/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapBackground.cpp
*/

#include "SMapBackground.hpp"

void 	addBackgroundMap()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driver = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	irr::scene::ISceneManager* sceneManager =
		device->getSceneManager();
	irr::scene::ISceneNode* skybox=sceneManager->addSkyBoxSceneNode(
		driver->getTexture("media/ciel.jpg"),
		driver->getTexture("media/ciel.jpg"),
		driver->getTexture("media/ciel.jpg"),
		driver->getTexture("media/ciel.jpg"),
		driver->getTexture("media/ciel.jpg"),
		driver->getTexture("media/ciel.jpg"));
}
