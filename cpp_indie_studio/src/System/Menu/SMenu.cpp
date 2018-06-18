/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenu.cpp
*/

#include "SMenu.hpp"

void SMenu::handleEvents() {
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driv = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	void *data;

	if (ECS::MEvent<ERefreshScene, void *>::pop(data)) {
		irr::gui::IGUIFont *font2 = FontTool::getFont(L"New Game", 0.13,
							      false);
		auto textureList = ECS::MComponent<CImageTexture>::getAll();
		irr::video::ITexture *imgSnow = nullptr;

		for (auto it = textureList.begin();
		     it != textureList.end();
		     std::advance(it, 1))
			if (it->second.id == "snow")
				imgSnow = it->second.img;
		env->clear();
		const irr::core::dimension2du &s = driv->getScreenSize();
		irr::gui::IGUIButton *button;
		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width / 2.0 - s.Width / 7.0),
			(int) (s.Height * (35.0 / 100.0)),
			(int) (s.Width / 2.0 + s.Width / 7.0),
			(int) (s.Height * (45.0 / 100.0))
					), 0, id_gui::BUTTON_MENU_NEW_GAME,
					L"New Game", L"Start a new game");
		button->setOverrideFont(font2);
		if (imgSnow)
			button->setImage(imgSnow);

		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width / 2.0 - s.Width / 7.0),
			(int) (s.Height * (50.0 / 100.0)),
			(int) (s.Width / 2.0 + s.Width / 7.0),
			(int) (s.Height * (60.0 / 100.0))
					), 0, id_gui::BUTTON_MENU_SAVE, L"Save",
					L"Start a back-up");
		button->setOverrideFont(font2);
		if (imgSnow)
			button->setImage(imgSnow);

		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width / 2.0 - s.Width / 7.0),
			(int) (s.Height * (65.0 / 100.0)),
			(int) (s.Width / 2.0 + s.Width / 7.0),
			(int) (s.Height * (75.0 / 100.0))
					), 0, id_gui::BUTTON_MENU_CTRL, L"CTRL",
					L"CTRL of the game");
		button->setOverrideFont(font2);
		if (imgSnow)
			button->setImage(imgSnow);

		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width / 2.0 - s.Width / 7.0),
			(int) (s.Height * (80.0 / 100.0)),
			(int) (s.Width / 2.0 + s.Width / 7.0),
			(int) (s.Height * (90.0 / 100.0))
					), 0, id_gui::BUTTON_MENU_QUIT, L"QUIT",
					L"Quit the game");
		button->setOverrideFont(font2);
		if (imgSnow)
			button->setImage(imgSnow);
		if (ECS::MComponent<CInventory>::getAll().size() < 2)
			return;
		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width / 2.0 + s.Width / 6.0),
			(int) (s.Height * 0.4),
			(int) (s.Width * 0.95),
			(int) (s.Height * 0.5)
				), 0, id_gui::BUTTON_MENU_CONTINUE
			, L"Continue");
		button->setOverrideFont(font2);
		if (imgSnow)
			button->setImage(imgSnow);
	}
}

void SMenu::init() {
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/Call_of_penguins2.png",
			       "menuTile"));
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/ice.jpeg",
			       "menuBackground"));
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/snow.jpg",
			       "snow"));
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/Back1.png",
			       "back1"));
	ECS::MComponent<CKeyIsDown>::create(ECS::MEntity::create(),
						CKeyIsDown());
}
