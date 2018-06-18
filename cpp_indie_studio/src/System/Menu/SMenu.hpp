/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenu.hpp
*/


#ifndef INDIESTUDIO_SMENU_HPP
#define INDIESTUDIO_SMENU_HPP

#include "ECS/System/MSystem.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "tool/FontTool.hpp"

class SMenu  : public ECS::ISystem<SMenu> {
public:
	void init() override;
	void handleEvents() override;
};

#endif /* INDIESTUDIO_SMENU_HPP */
