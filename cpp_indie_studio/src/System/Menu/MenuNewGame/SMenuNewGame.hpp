/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuNewGame.hpp
*/


#ifndef INDIESTUDIO_SMENUNEWGAME_HPP
#define INDIESTUDIO_SMENUNEWGAME_HPP

#include "ECS/System/MSystem.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "tool/FontTool.hpp"
#include "Component/Menu/CMenu.hpp"
#include "Component/Game/CTurn.hpp"
#include "Entity/Player/EPlayer.hpp"

class SMenuNewGame : public ECS::ISystem<SMenuNewGame> {
public:
	void init() override ;
	void handleEvents() override;
private:
	irr::gui::IGUICheckBox *addCheckBox(irr::core::rect<irr::s32> boxRect,
			 irr::core::rect<irr::s32> textRect,
			 const wchar_t *textStatic, int id, bool check = false);
	void refresh();
	void boxGestion(int id);
	void startGestion();
};


#endif /* INDIESTUDIO_SMENUNEWGAME_HPP */
