/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuLoadingRender.hpp
*/


#ifndef INDIESTUDIO_SMENULOADINGRENDER_HPP
#define INDIESTUDIO_SMENULOADINGRENDER_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Events/EScene.hpp"
#include "Component/Id.hpp"
#include "tool/FontTool.hpp"
#include "Component/Menu/CTime.hpp"

class SMenuLoadingRender : public ECS::ISystem<SMenuLoadingRender> {
public:
	void init() override ;
	void update(ECS::DeltaTime delta) override;
};



#endif /* INDIESTUDIO_SMENULOADINGRENDER_HPP */
