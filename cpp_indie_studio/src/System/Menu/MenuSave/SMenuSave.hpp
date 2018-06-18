/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuSave.hpp
*/


#ifndef INDIESTUDIO_SMENUSAVE_HPP
#define INDIESTUDIO_SMENUSAVE_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Events/EScene.hpp"
#include "Component/Id.hpp"
#include "tool/FontTool.hpp"

class SMenuSave : public ECS::ISystem<SMenuSave> {
public:
	void handleEvents() override ;
};
#endif /* INDIESTUDIO_SMENUSAVE_HPP */
