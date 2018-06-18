/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenu.cpp
*/

#include "SRenderMenu.hpp"
#include <iostream>

void SRenderMenu::preUpdate(ECS::DeltaTime delta)
{
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->beginScene(true, true, irr::video::SColor(255, 100, 100, 250));
}

void SRenderMenu::update(ECS::DeltaTime delta)
{
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	const irr::core::dimension2du &s = driv->getScreenSize();
	auto textureList = ECS::MComponent<CImageTexture>::getAll();
	irr::video::ITexture *imgTitle = nullptr;
	irr::video::ITexture *imgBack = nullptr;

	for (auto it = textureList.begin();
	     it != textureList.end();
	     std::advance(it, 1)) {
		if (it->second.id == "menuTile")
			imgTitle = it->second.img;
		if (it->second.id == "menuBackground")
			imgBack = it->second.img;
	}
	if (imgBack) {
		irr::core::dimension2d<irr::u32> imgS = imgBack->getSize();
		driv->draw2DImage(imgBack,
				  irr::core::rect<irr::s32>(
				  	0, 0, s.Width, s.Height),
				  irr::core::rect<irr::s32>(
				  	0, 0, imgS.Width, imgS.Height), 0,
				  0, true);
	}
	if (imgTitle) {
		irr::core::dimension2d<irr::u32> imgS = imgTitle->getSize();
		driv->draw2DImage(imgTitle, irr::core::rect<irr::s32>(
			(int) (s.Width * 0.2), (int) (s.Height * 0.08),
			(int) (s.Width * 0.8), (int) (s.Height * 0.08 +
						      ((float) imgS.Height /
						       (float) imgS.Width *
						       (float) s.Width * 0.6))),
				  irr::core::rect<irr::s32>(0, 0, imgS.Width,
							    imgS.Height), 0, 0,
				  true);
	}
	env->drawAll();
}

void SRenderMenu::postUpdate(ECS::DeltaTime delta)
{
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->endScene();
}
