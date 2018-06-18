/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SFallDamage.hpp
*/


#ifndef INDIESTUDIO_SFALLDAMAGE_HPP
#define INDIESTUDIO_SFALLDAMAGE_HPP

#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SFallDamage : public ECS::ISystem<SFallDamage> {
public:
	void update(ECS::DeltaTime delta) override ;
};

#endif /* INDIESTUDIO_SFALLDAMAGE_HPP */
