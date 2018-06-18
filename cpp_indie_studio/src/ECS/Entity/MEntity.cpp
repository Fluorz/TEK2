/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Entity.cpp
*/

#include "MEntity.hpp"

ECS::MEntity &ECS::MEntity::getInstance()
{
	static MEntity instance;
	return instance;
}

ECS::Entity ECS::MEntity::create()
{
	return MEntity::getInstance().last++;
}

void ECS::MEntity::remove(Entity entity)
{
	for (auto &mComponent : getInstance().entities[entity]) {
		mComponent->erase(entity);
	}
	getInstance().entities.erase(entity);
}

void ECS::MEntity::addComponent(Entity entity, IMComponent *component)
{
	getInstance().entities[entity].push_back(component);
}

void
ECS::MEntity::removeComponent(ECS::Entity entity, ECS::IMComponent *component)
{
	auto *mComponents = &getInstance().entities[entity];
	for (auto mComponent = mComponents->begin();
	     mComponent != mComponents->end(); mComponent++) {
		if (*mComponent == component) {
			mComponents->erase(mComponent);
			break;
		}
	}
}
