/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SIrrlichtEvent.hpp
*/


#ifndef INDIESTUDIO_SIRRLICHTEVENT_HPP
#define INDIESTUDIO_SIRRLICHTEVENT_HPP

#include <irrlicht.h>
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "System/Scene/SScene.hpp"

#include "Events/EIrrlicht.hpp"
#include "Events/EScene.hpp"
#include "Events/EKeyInput.hpp"
#include "Events/EvMenu.hpp"

class SIrrlichtEvent : public ECS::ISystem<SIrrlichtEvent> {
public:
	void handleEvents() override;
private:
	void gui_button_cliked(irr::SEvent &event);
	void key_input_event(irr::SEvent &event);
	void gui_checkBox_cliked(irr::SEvent &event);
	void escape_event();
};


#endif /* INDIESTUDIO_SIRRLICHTEVENT_HPP */
