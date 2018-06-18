/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenueCtrl.cpp
*/


#include "System/Menu/MenuCtrl/SRenderMenuCtrl.hpp"

void SRenderMenuCtrl::preUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->beginScene(true, true, irr::video::SColor(255, 100, 100, 250));
}

void SRenderMenuCtrl::update(ECS::DeltaTime delta) {
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	env->drawAll();
}

void SRenderMenuCtrl::postUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->endScene();
}



