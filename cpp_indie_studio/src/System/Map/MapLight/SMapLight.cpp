/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        SMapLight.cpp
*/

#include "SMapLight.hpp"

void createLight()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driver = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	irr::scene::ISceneManager* sceneManager =
		device->getSceneManager();
	irr::scene::ILightSceneNode* light;
	irr::scene::ILightSceneNode* secondLight;

	light = sceneManager->addLightSceneNode(
		0,
		irr::core::vector3df(
			-40,
			200,
			100
		));
	secondLight = sceneManager->addLightSceneNode(
		0,
		irr::core::vector3df(
			540,
			200,
			100
	));
}
