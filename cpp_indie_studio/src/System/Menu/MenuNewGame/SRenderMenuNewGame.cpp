/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuNewGame.cpp
*/

#include "System/Menu/MenuNewGame/SRenderMenuNewGame.hpp"

void SRenderMenuNewGame::preUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->beginScene(true, true, irr::video::SColor(255, 50, 50, 250));
}

void SRenderMenuNewGame::update(ECS::DeltaTime delta) {
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	const irr::core::dimension2du &s = driv->getScreenSize();
	auto textureList = ECS::MComponent<CImageTexture>::getAll();
	irr::video::ITexture *imgBack = nullptr;

	for (auto it = textureList.begin();
	     it != textureList.end();
	     std::advance(it, 1))
		if (it->second.id == "menuBackground")
			imgBack = it->second.img;
	if (imgBack) {
		irr::core::dimension2d<irr::u32> imgS = imgBack->getSize();
		driv->draw2DImage(imgBack,
				  irr::core::rect<irr::s32>(
					  0, 0, s.Width, s.Height),
				  irr::core::rect<irr::s32>(
					  0, 0, imgS.Width, imgS.Height), 0,
				  0, true);
	}
	env->drawAll();
}

void SRenderMenuNewGame::postUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->endScene();
}
