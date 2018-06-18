/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SPhysic.hpp
*/


#ifndef INDIESTUDIO_PHYSICS_HPP
#define INDIESTUDIO_PHYSICS_HPP

#include <ECS/System/ISystem.hpp>

class SPhysic : public ECS::ISystem<SPhysic> {
public:
	void update(ECS::DeltaTime delta) override;
};


#endif /* INDIESTUDIO_PHYSICS_HPP */
