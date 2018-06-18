/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CKeyMapStatic.cpp
*/


#include <ECS/Component/MComponent.hpp>
#include "CKeyMapStatic.hpp"
#include "Component/Id.hpp"

CKeyMapStatic::CKeyMapStatic()
{
	KeyMap.emplace("left", irr::EKEY_CODE::KEY_LEFT);
	KeyMap.emplace("right", irr::EKEY_CODE::KEY_RIGHT);
	KeyMap.emplace("jump", irr::EKEY_CODE::KEY_SPACE);
	KeyMap.emplace("switchWeapon", irr::EKEY_CODE::KEY_KEY_N);
	KeyMap.emplace("aimUp", irr::EKEY_CODE::KEY_UP);
	KeyMap.emplace("aimDown", irr::EKEY_CODE::KEY_DOWN);
	KeyMap.emplace("shoot", irr::EKEY_CODE::KEY_TAB);

	int to_add = ECS::MComponent<CKeyMapStatic>::getAll().size()
		* KeyMap.size();

	ButtonCode.emplace("left", id_gui::BUTTON1_PLAYER_LEFT + to_add);
	ButtonCode.emplace("right", id_gui::BUTTON1_PLAYER_RIGHT + to_add);
	ButtonCode.emplace("jump", id_gui::BUTTON1_PLAYER_JUMP + to_add);
	ButtonCode.emplace("switchWeapon",
			   id_gui::BUTTON1_PLAYER_SWITCH + to_add);
	ButtonCode.emplace("aimUp", id_gui::BUTTON1_PLAYER_AIMUP + to_add);
	ButtonCode.emplace("aimDown", id_gui::BUTTON1_PLAYER_AIMDOWN + to_add);
	ButtonCode.emplace("shoot", id_gui::BUTTON1_PLAYER_SKIP + to_add);
	waiting = "";
}
