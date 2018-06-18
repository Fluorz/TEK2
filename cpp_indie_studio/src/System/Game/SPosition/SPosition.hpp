/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SPosition.hpp
*/


#ifndef INDIESTUDIO_SPOSITION_HPP
#define INDIESTUDIO_SPOSITION_HPP


#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SPosition : public ECS::ISystem<SPosition> {
public:
	void handleEvents() override ;
	void update(ECS::DeltaTime delta) override ;
};


#endif /* INDIESTUDIO_SPOSITION_HPP */
