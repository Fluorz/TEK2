/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRenderGame.hpp
*/


#ifndef INDIESTUDIO_SRENDERGAME_HPP
#define INDIESTUDIO_SRENDERGAME_HPP

#include "ECS/System/MSystem.hpp"
#include "System/Map/MapBackground/SMapBackground.hpp"
#include "System/Map/MapCamera/SMapCamera.hpp"
#include "System/Map/MapLight/SMapLight.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"

#include <string>
#include <vector>
#include "irrlicht.h"

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"

class SRenderGame : public ECS::ISystem<SRenderGame> {
public:
	void init() override;
	void handleEvents() override ;
	void update(ECS::DeltaTime delta) override ;
	void postUpdate(ECS::DeltaTime delta) override ;
	void preUpdate(ECS::DeltaTime delta) override ;
};



#endif /* INDIESTUDIO_SRENDERGAME_HPP */
