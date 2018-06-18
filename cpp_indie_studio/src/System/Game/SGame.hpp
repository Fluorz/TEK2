/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SGame.hpp
*/


#ifndef INDIESTUDIO_SGAME_HPP
#define INDIESTUDIO_SGAME_HPP

#include "Component/Map/CMap.hpp"
#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "System/Map/MapDestruction/SMapDestruction.hpp"
#include "Component/Graphical/CMesh.hpp"
#include "Component/Game/CMunition.hpp"
#include "AI/include/AiCore.hpp"

class SGame : public ECS::ISystem<SGame> {
public:
	void init() override;
	void handleEvents() override ;
	void update(ECS::DeltaTime delta) override ;
	void postUpdate(ECS::DeltaTime delta) override ;
	void preUpdate(ECS::DeltaTime delta) override ;
private:
	void playerGestion(ECS::Entity);
	void aiGestion(ECS::Entity);
	void move(ECS::Entity, int type);
	void shoot(ECS::Entity);
	void aimDir(ECS::Entity, int type);
	void switchWeapon(ECS::Entity);
	void jump(ECS::Entity);
};


#endif /* INDIESTUDIO_SGAME_HPP */
