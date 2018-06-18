/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRotation.cpp
*/


#include "SRotation.hpp"

void SRotation::update(ECS::DeltaTime delta)
{
	for (auto it = ECS::MComponent<CSkin>::getAll().begin();
	     ECS::MComponent<CSkin>::getAll().end() != it;
	     std::advance(it, 1)) {
		auto rot = ECS::MComponent<CRotation>::get(it->first);
		if (!rot)
			continue;
		it->second.node->setRotation(irr::core::vector3df(
			0, rot->dir, 0));
		auto weapon = ECS::MComponent<CWeapon>::get(it->first);
		if (weapon->node) {
			weapon->node->setRotation(irr::core::vector3df(
				0, rot->dir,
				rot->aim * (rot->dir > 100 ? -1 : 1)));
		}
	}
}
