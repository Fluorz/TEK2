/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SScene.cpp
*/

#include <System/Game/Gravity/SCravity.hpp>
#include <System/Game/FallDamage/SFallDamage.hpp>
#include <System/Game/SMunition/SMunition.hpp>
#include <System/Game/Kill/SKill.hpp>
#include "SScene.hpp"

void SScene::handleEvents() {
	int type = -1;

	while (ECS::MEvent<ECloseScene, int>::pop(type)) {
		switch (type) {
			case id_scene::SCENE_MENU:
				SRenderMenu::stop();
				SMenu::stop();
				break;
			case id_scene::SCENE_MENU_CTRL:
				SRenderMenuCtrl::stop();
				SMenuCtrl::stop();
				break;
			case id_scene::SCENE_MENU_SAVE:
				SRenderMenuSave::stop();
				SMenuSave::stop();
				break;
			case id_scene::SCENE_MENU_NEW_GAME:
				SRenderMenuNewGame::stop();
				SMenuNewGame::stop();
				break;
			case id_scene ::SCENE_LOADING:
				SMenuLoadingRender::stop();
			case id_scene::SCENE_GAME:
				SRenderGame::stop();
				SGame::stop();
				SPosition::stop();
				SRotation::stop();
				SGravity::stop();
				SFallDamage::stop();
				SMunition::stop();
				SKill::stop();
			default:
				break;
		}
	}
	while (ECS::MEvent<EStartScene, int>::pop(type)) {
		switch (type) {
			case id_scene::SCENE_MENU:
				SRenderMenu::start();
				SMenu::start();
				break;
			case id_scene::SCENE_MENU_CTRL:
				SRenderMenuCtrl::start();
				SMenuCtrl::start();
				break;
			case id_scene::SCENE_MENU_SAVE:
				SRenderMenuSave::start();
				SMenuSave::start();
				break;
			case id_scene::SCENE_MENU_NEW_GAME:
				SRenderMenuNewGame::start();
				SMenuNewGame::start();
				break;
			case id_scene::SCENE_GAME:
				SRenderGame::start();
				SGame::start();
				SPosition::start();
				SRotation::start();
				SGravity::start();
				SFallDamage::start();
				SMunition::start();
				SKill::start();
			default:
				break;
		}
		ECS::MEvent<ERefreshScene, void*>::push(nullptr);
	}
}
