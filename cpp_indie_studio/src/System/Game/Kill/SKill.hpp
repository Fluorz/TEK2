/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SKill.hpp
*/


#ifndef INDIESTUDIO_SKILL_HPP
#define INDIESTUDIO_SKILL_HPP

#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SKill : public ECS::ISystem<SKill> {
public:
	void update(ECS::DeltaTime delta) override ;
};

#endif /* INDIESTUDIO_SKILL_HPP */
