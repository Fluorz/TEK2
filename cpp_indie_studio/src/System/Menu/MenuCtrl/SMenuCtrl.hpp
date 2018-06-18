/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuCtrl.hpp
*/


#ifndef INDIESTUDIO_SMENUCTRL_HPP
#define INDIESTUDIO_SMENUCTRL_HPP

#include "ECS/System/MSystem.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "tool/FontTool.hpp"
#include "Component/Game/CKeyMapStatic.hpp"
#include "Events/EKeyInput.hpp"
#include "Events/EvMenu.hpp"

class SMenuCtrl  : public ECS::ISystem<SMenuCtrl> {
public:
	void init() override;
	void handleEvents() override;
private:
	void addBoxKey(CKeyMapStatic &KeyMap, float x, float y, int player);
	void refresh();
	void try_change(irr::SEvent::SKeyInput);
	void edit_waiting(int);
};


#endif /* INDIESTUDIO_SMENUCTRL_HPP */
