/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuSave.cpp
*/


#include "SMenuSave.hpp"

void SMenuSave::handleEvents() {
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	void *data;

	if (ECS::MEvent<ERefreshScene, void*>::pop(data)) {
		env->clear();
		const irr::core::dimension2du& s = driv->getScreenSize();
		env->addButton(irr::core::rect<irr::s32>(
			(int)(s.Width / 2.0 - s.Width / 7.0),
			(int)(s.Height * (35.0/100.0)),
			(int)(s.Width / 2.0 + s.Width / 7.0),
			(int)(s.Height * (45.0/100.0))
		), 0, BUTTON_MENU_SAVE_BACK, L"BACK TO MENU");
	}
}
