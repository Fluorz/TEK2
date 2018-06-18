/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuCtrl.cpp
*/

#include "SMenuCtrl.hpp"

std::map<int, std::string> keyString = {
	{0x08, "BACKSPACE"},
	{0x09, "TAB"},
	{0x0D, "ENTER"},
	{0x10, "SHIFT"},
	{0x11, "CTRL"},
	{0x12, "ALT"},
	{0x13, "PAUSE"},
	{0x14, "CAPS LOCK"},
	{0x1B, "ESC"},
	{0x20, "SPACEBAR"},
	{0x21, "PAGE UP"},
	{0x22, "PAGE DOWN"},
	{0x23, "END"},
	{0x24, "HOME"},
	{0x25, "LEFT"},
	{0x26, "UP"},
	{0x27, "RIGHT"},
	{0x28, "DOWN"},
	{0x29, "SELECT"},
	{0x2D, "INSERT"},
	{0x2E, "DELETE"},
	{0x2F, "HELP"},
	{0x30, "0"},
	{0x31, "1"},
	{0x32, "2"},
	{0x33, "3"},
	{0x34, "4"},
	{0x35, "5"},
	{0x36, "6"},
	{0x37, "7"},
	{0x38, "8"},
	{0x39, "9"},
	{0x41, "A"},
	{0x42, "B"},
	{0x43, "C"},
	{0x44, "D"},
	{0x45, "E"},
	{0x46, "F"},
	{0x47, "G"},
	{0x48, "H"},
	{0x49, "I"},
	{0x4A, "J"},
	{0x4B, "K"},
	{0x4C, "L"},
	{0x4D, "M"},
	{0x4E, "N"},
	{0x4F, "O"},
	{0x50, "P"},
	{0x51, "Q"},
	{0x52, "R"},
	{0x53, "S"},
	{0x54, "T"},
	{0x55, "U"},
	{0x56, "V"},
	{0x57, "W"},
	{0x58, "X"},
	{0x59, "Y"},
	{0x5A, "Z"},
	{0x5B, "LEFT WIN"},
	{0x5C, "RIGHT WIN"},
	{0x60, "0"},
	{0x61, "1"},
	{0x62, "2"},
	{0x63, "3"},
	{0x64, "4"},
	{0x65, "5"},
	{0x66, "6"},
	{0x67, "7"},
	{0x68, "8"},
	{0x69, "9"},
	{0x6A, "MUL"},
	{0x6B, "ADD"},
	{0x6C, "SEP"},
	{0x6D, "SUB"},
	{0x6E, "DECIMAL"},
	{0x6F, "DIVIDE"},
	{0x70, "F1"},
	{0x71, "F2"},
	{0x72, "F3"},
	{0x73, "F4"},
	{0x74, "F5"},
	{0x75, "F6"},
	{0x76, "F7"},
	{0x77, "F8"},
	{0x78, "F9"},
	{0x79, "F10"},
	{0x7A, "F11"},
	{0x7B, "F12"},
	{0x7C, "F13"},
	{0x7D, "F14"},
	{0x7E, "F15"},
	{0x7F, "F16"},
	{0x80, "F17"},
	{0x81, "F18"},
	{0x82, "F19"},
	{0x83, "F20"},
	{0x84, "F21"},
	{0x85, "F22"},
	{0x86, "F23"},
	{0x87, "F24"},
	{0x90, "NUM LOCK"},
	{0x91, "SCROLL"},
	{0xA0, "LSHIFT"},
	{0xA1, "RSHIFT"},
	{0xA2, "LCONTROL"},
	{0xA3, "RCONTROL"},
	{0xA4, "LMENU"},
	{0xA5, "RMENU"},
	{0xBB, "+"},
	{0xBC, ","},
	{0xBD, "-"},
	{0xBE, "."}
};

void SMenuCtrl::refresh()
{
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;

	env->clear();
	const irr::core::dimension2du &s = driv->getScreenSize();
	env->addButton(irr::core::rect<irr::s32>(
		(10), (10),
		(int) (s.Width / 8.0),
		(int) (s.Height * 0.06)
	), 0, BUTTON_MENU_CTRL_BACK, L"BACK");

	auto KeyMapList = ECS::MComponent<CKeyMapStatic>::getAll();
	if (KeyMapList.size() == 4) {
		auto it = KeyMapList.begin();
		addBoxKey(it->second, 0, 0.07, 1);
		std::advance(it, 1);
		addBoxKey(it->second, 0.5, 0.07, 2);
		std::advance(it, 1);
		addBoxKey(it->second, 0, 0.52, 3);
		std::advance(it, 1);
		addBoxKey(it->second, 0.5, 0.52, 4);
	}

}

void SMenuCtrl::handleEvents()
{
	void *data;
	irr::SEvent::SKeyInput key;
	int id = 0;

	if (ECS::MEvent<ERefreshScene, void *>::pop(data))
		this->refresh();
	if (ECS::MEvent<EKeyInputDown, irr::SEvent::SKeyInput>::pop(key))
		this->try_change(key);
	if (ECS::MEvent<EMenuCtrlWaiting, int>::pop(id))
		this->edit_waiting(id);
}

void SMenuCtrl::init()
{
	ECS::MComponent<CKeyMapStatic>::create(ECS::MEntity::create(),
					       CKeyMapStatic());
	ECS::MComponent<CKeyMapStatic>::create(ECS::MEntity::create(),
					       CKeyMapStatic());
	ECS::MComponent<CKeyMapStatic>::create(ECS::MEntity::create(),
					       CKeyMapStatic());
	ECS::MComponent<CKeyMapStatic>::create(ECS::MEntity::create(),
					       CKeyMapStatic());
}

void SMenuCtrl::addBoxKey(CKeyMapStatic &KeyMap, float x, float y, int player)
{
	auto it = KeyMap.KeyMap.begin();
	auto &env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto &driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	const irr::core::dimension2du &s = driv->getScreenSize();
	float p = 0.45;
	int i = 1;
	irr::core::stringw str = it->first.c_str();
	irr::gui::IGUIButton *button;
	irr::gui::IGUIStaticText *text;
	std::string sPlayer = "Player " + std::to_string(player);
	str = sPlayer.c_str();

	text = env->addStaticText(str.c_str(),
				  irr::core::rect<irr::s32>(
					  (int) (s.Width * x + p * 0.05),
					  (int) (s.Height * y),
					  (int) (s.Width * (x + p * (0.95))),
					  (int) (s.Height * (y + p * 0.111))
				  ), true);
	text->setOverrideFont(FontTool::getFont(L"AAAAAAAAAA",
						(float) (p * 0.4), false,
						CLOSEST_DOWN));
	text->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
	while (it != KeyMap.KeyMap.end()) {
		int id = KeyMap.ButtonCode.find(it->first)->second;
		str = it->first.c_str();
		button = env->addButton(irr::core::rect<irr::s32>(
			(int) (s.Width * (x + p * (0.1))),
			(int) (s.Height * (y + p * (0.125 * i))),
			(int) (s.Width * (x + p * (0.5))),
			(int) (s.Height * (y + p * ((0.125 * i) + 0.111)))
		), 0, id, str.c_str());
		button->setOverrideFont(FontTool::getFont(L"AAAAAAAAAA",
							  (float) (p * 0.4),
							  false, CLOSEST_DOWN));
		str = keyString.find(it->second)->second.c_str();
		text = env->addStaticText(
			KeyMap.waiting != it->first ? str.c_str() : L"...",
			irr::core::rect<irr::s32>(
				(int) (s.Width * (x + p * (0.55))),
				(int) (s.Height * (y + p * (0.125 * i))),
				(int) (s.Width * (x + p * (0.95))),
				(int) (s.Height *
				       (y + p * ((0.125 * i) + 0.111)))
			), true);
		text->setOverrideFont(
			FontTool::getFont(L"AAAAAAAAAA", (float) (p * 0.4),
					  false, CLOSEST_DOWN));
		text->setTextAlignment(irr::gui::EGUIA_CENTER,
				       irr::gui::EGUIA_CENTER);
		text->setBackgroundColor(
			irr::video::SColor(255, 170, 170, 255));
		std::advance(it, 1);
		i++;
	}
}

void SMenuCtrl::try_change(irr::SEvent::SKeyInput key)
{
	auto &KeyMapList = ECS::MComponent<CKeyMapStatic>::getAll();
	auto it = KeyMapList.begin();

	while (it != KeyMapList.end()) {
		if (it->second.KeyMap.find(it->second.waiting)
		    != it->second.KeyMap.end() &&
		    keyString.find(key.Key) != keyString.end()) {
			it->second.KeyMap.find(it->second.waiting)->second
				= key.Key;
			it->second.waiting = "";
			this->refresh();
			break;
		}
		std::advance(it, 1);
	}
}

void SMenuCtrl::edit_waiting(int wait)
{
	auto &KeyMapList = ECS::MComponent<CKeyMapStatic>::getAll();
	auto it = KeyMapList.begin();

	while (it != KeyMapList.end()) {
		if (it->second.waiting != "")
			it->second.waiting = "";
		std::advance(it, 1);
	}
	it = KeyMapList.begin();
	std::advance(it, (wait - BUTTON1_PLAYER_LEFT) / 7);
	wait = (wait - BUTTON1_PLAYER_LEFT) % 7;
	switch (wait) {
		case 0:
			it->second.waiting = "left";
			break;
		case 1:
			it->second.waiting = "right";
			break;
		case 2:
			it->second.waiting = "jump";
			break;
		case 3:
			it->second.waiting = "switchWeapon";
			break;
		case 4:
			it->second.waiting = "aimUp";
			break;
		case 5:
			it->second.waiting = "aimDown";
			break;
		case 6:
			it->second.waiting = "shoot";
			break;
	}
	this->refresh();
}
