/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenu.hpp
*/


#ifndef INDIESTUDIO_SRENDERMENU_HPP
#define INDIESTUDIO_SRENDERMENU_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"

class SRenderMenu : public ECS::ISystem<SRenderMenu> {
public:
	void preUpdate(ECS::DeltaTime delta) override;
	void update(ECS::DeltaTime delta) override;
	void postUpdate(ECS::DeltaTime delta) override;
};

#endif /* INDIESTUDIO_SRENDERMENU_HPP */
