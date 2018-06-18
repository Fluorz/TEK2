/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SResize.cpp
*/

#include <iostream>
#include "SResize.hpp"

void SResize::update(ECS::DeltaTime delta)
{
	(void)delta;
	auto &ScreenSizeList = ECS::MComponent<CScreenSize>::getAll();
	if (ScreenSizeList.empty())
		return;
	auto &ScreenSize = ScreenSizeList.begin()->second;

	auto &drivList = ECS::MComponent<CIrrMain>::getAll();
	if (drivList.empty())
		return;
	auto &driv = drivList.begin()->second.driver;
	const irr::core::dimension2du& s = driv->getScreenSize();

	if (ScreenSize.height == -1 || ScreenSize.width == -1) {
		ScreenSize.height = (int)s.Height;
		ScreenSize.width = (int)s.Width;
	} else if ((int)s.Height != ScreenSize.height ||
		(int)s.Width != ScreenSize.width) {
		ScreenSize.height = (int)s.Height;
		ScreenSize.width = (int)s.Width;
		ECS::MEvent<ERefreshScene, void*>::push(nullptr);
	}
}

void SResize::init()
{
	ECS::MComponent<CScreenSize>::create(ECS::MEntity::create(),
					     CScreenSize{});
}
