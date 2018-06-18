/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SIrrlichtEvent.cpp
*/

#include "SIrrlichtEvent.hpp"

void SIrrlichtEvent::handleEvents()
{
	irr::SEvent event;

	while (ECS::MEvent<EIrrlicht, irr::SEvent>::pop(event)) {
		if (event.EventType == irr::EET_GUI_EVENT) {
			if (event.GUIEvent.EventType ==
			    irr::gui::EGET_BUTTON_CLICKED)
				this->gui_button_cliked(event);
			if (event.GUIEvent.EventType ==
			    irr::gui::EGET_CHECKBOX_CHANGED)
				this->gui_checkBox_cliked(event);
		}
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			this->key_input_event(event);

	}
}

void SIrrlichtEvent::gui_button_cliked(irr::SEvent &event)
{
	irr::s32 id = event.GUIEvent.Caller->getID();
	if (id >= BUTTON1_PLAYER_LEFT && id <= BUTTON4_PLAYER_SKIP) {
		ECS::MEvent<EMenuCtrlWaiting, int>::push(id);
		return;
	}
	switch (id) {
		case id_gui::BUTTON_MENU_CTRL_BACK:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU_CTRL);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU);
			break;
		case id_gui::BUTTON_MENU_SAVE_BACK:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU_SAVE);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU);
			break;
		case id_gui::BUTTON_MENU_NEW_GAME_BACK:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU_NEW_GAME);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU);
			break;
		case id_gui::BUTTON_MENU_NEW_GAME:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU_NEW_GAME);
			break;
		case id_gui::BUTTON_MENU_CTRL:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU_CTRL);
			break;
		case id_gui::BUTTON_MENU_SAVE:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_MENU_SAVE);
			break;
		case id_gui::BUTTON_MENU_CONTINUE:
			ECS::MEvent<ECloseScene, int>::
			push(id_scene::SCENE_MENU);
			ECS::MEvent<EStartScene, int>::
			push(id_scene::SCENE_GAME);
			break;
		case id_gui::BUTTON_MENU_NEW_GAME_START:
			ECS::MEvent<EStartNewGame, void *>::push(nullptr);
			break;
		case id_gui::BUTTON_MENU_QUIT:
			auto dev = ECS::MComponent<CIrrMain>::
			getAll().begin()->second.device;
			dev->closeDevice();
			break;
	}
}

void SIrrlichtEvent::key_input_event(irr::SEvent &event)
{
	auto &KeyIsDownList = ECS::MComponent<CKeyIsDown>::getAll();

	if (!KeyIsDownList.empty()) {
		auto &KeyIsDown = KeyIsDownList.begin()->second;
		if (!KeyIsDown.KeyIsDown[event.KeyInput.Key]) {
			if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
			    event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE)
				this->escape_event();
			else
				ECS::MEvent<EKeyInputDown,
					irr::SEvent::SKeyInput>::
				push(event.KeyInput);
		}
		KeyIsDown.KeyIsDown[event.KeyInput.Key] =
			event.KeyInput.PressedDown;
	}
}

void SIrrlichtEvent::gui_checkBox_cliked(irr::SEvent &event)
{
	ECS::MEvent<EClickBox, int>::push(event.GUIEvent.Caller->getID());
}

void SIrrlichtEvent::escape_event()
{
	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;

	if (SMenu::getInstance().isStart()) {
		dev->closeDevice();
		return;
	}
	int closeId = -1;
	if (SGame::getInstance().isStart())
			closeId = id_scene ::SCENE_GAME;
	if (SMenuNewGame::getInstance().isStart())
		closeId = id_scene ::SCENE_MENU_NEW_GAME;
	if (SMenuSave::getInstance().isStart())
		closeId = id_scene ::SCENE_MENU_SAVE;
	if (SMenuCtrl::getInstance().isStart())
		closeId = id_scene ::SCENE_MENU_CTRL;
	ECS::MEvent<ECloseScene, int>::push(closeId);
	ECS::MEvent<EStartScene, int>::push(id_scene::SCENE_MENU);
}
