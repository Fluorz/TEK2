/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuSave.cpp
*/

#include "System/Menu/MenuSave/SRenderMenuSave.hpp"

void SRenderMenuSave::preUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->beginScene(true, true, irr::video::SColor(255, 50, 50, 250));
}

void SRenderMenuSave::update(ECS::DeltaTime delta) {
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	env->drawAll();
}

void SRenderMenuSave::postUpdate(ECS::DeltaTime delta) {
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	driv->endScene();
}


