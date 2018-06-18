/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMunition.hpp
*/


#ifndef INDIESTUDIO_SMUNITION_HPP
#define INDIESTUDIO_SMUNITION_HPP

#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SMunition : public ECS::ISystem<SMunition> {
public:
	void update(ECS::DeltaTime delta) override ;
};

#endif /* INDIESTUDIO_SMUNITION_HPP */
