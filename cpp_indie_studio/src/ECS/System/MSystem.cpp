/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MSystem.cpp
*/


#include <ECS/Event/EventStore.hpp>
#include "MSystem.hpp"

ECS::MSystem &ECS::MSystem::getInstance()
{
	static MSystem instance;
	return instance;
}

void ECS::MSystem::updateAll(DeltaTime delta)
{
	for (auto &system : getInstance().systems)
		if (system->isStart())
			system->handleEvents();
	for (auto &system : getInstance().systems)
		if (system->isStart())
			system->preUpdate(delta);
	for (auto &system : getInstance().systems)
		if (system->isStart())
			system->update(delta);
	for (auto &system : getInstance().systems)
		if (system->isStart())
			system->postUpdate(delta);
	EventStore::clearAll();
}

void ECS::MSystem::add(SourceSystem *system)
{
	getInstance().systems.push_back(system);
	system->init();
}
