/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SCravity.hpp
*/


#ifndef INDIESTUDIO_SCRAVITY_HPP
#define INDIESTUDIO_SCRAVITY_HPP

#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SGravity : public ECS::ISystem<SGravity> {
public:
	void update(ECS::DeltaTime delta) override ;
};

#endif /* INDIESTUDIO_SCRAVITY_HPP */
