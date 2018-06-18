/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        camera.cpp
*/

#include "SMapCamera.hpp"

void 	addCameraMap()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driver = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	irr::scene::ISceneManager* sceneManager =
		device->getSceneManager();
	irr::scene::ICameraSceneNode *cam = sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 140, 250), irr::core::vector3df(256,140,0));

	// Set Camera's X, Y, Z  Position
	cam->setPosition(irr::core::vector3df(255, cam->getPosition().Y, cam->getPosition().Z));
}
