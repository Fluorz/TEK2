/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRotation.hpp
*/


#ifndef INDIESTUDIO_SROTATION_HPP
#define INDIESTUDIO_SROTATION_HPP


#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"

class SRotation : public ECS::ISystem<SRotation> {
public:
	void update(ECS::DeltaTime delta) override ;
};



#endif /* INDIESTUDIO_SROTATION_HPP */
