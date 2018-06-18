/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** irrlichtComponent.cpp
*/


#include "irrlichtComponent.hpp"
#include <utility>

CImageTexture::CImageTexture(const std::string &path, std::string _id)
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &driver = DeviceContener.begin()->second.driver;
	img = driver->getTexture(path.c_str());
	id = std::move(_id);
}
