/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SResize.hpp
*/


#ifndef INDIESTUDIO_SRESIZE_HPP
#define INDIESTUDIO_SRESIZE_HPP


#include <irrlicht.h>
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"

#include "Events/EScene.hpp"

class SResize: public ECS::ISystem<SResize> {
public:
	void init() override;
	void update(ECS::DeltaTime delta) override;
};

#endif /* INDIESTUDIO_SRESIZE_HPP */
