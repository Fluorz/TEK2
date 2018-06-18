/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SPosition.cpp
*/

#include "SPosition.hpp"

void SPosition::handleEvents()
{
}

void SPosition::update(ECS::DeltaTime delta)
{
	for (auto it = ECS::MComponent<CSkin>::getAll().begin();
		ECS::MComponent<CSkin>::getAll().end() != it;
		std::advance(it, 1)) {
		auto pos = ECS::MComponent<CPos>::get(it->first);
		if (!pos)
			continue;
		it->second.node->setPosition(irr::core::vector3df(
			pos->x, pos->y, 51.0f));
		auto weapon = ECS::MComponent<CWeapon>::get(it->first);
		if (weapon->node) {
			weapon->node->setPosition(irr::core::vector3df(
				pos->x + 3, pos->y + 5, 52.0f));
		}
	}
}
