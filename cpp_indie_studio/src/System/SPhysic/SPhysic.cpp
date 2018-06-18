/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SPhysic.cpp
*/

#include <ECS/Component/MComponent.hpp>
#include <Component/Physic/CSpeed.hpp>
#include <Component/Physic/CPos.hpp>
#include <ECS/System/ISystem.hpp>
#include <Component/Physic/CGravity.hpp>

#include "SPhysic.hpp"

void SPhysic::update(ECS::DeltaTime delta)
{
	for (auto &component : ECS::MComponent<CPos>::getAll()) {
		auto &pos = component.second;

		if (pos.relative) {
			auto relativePos =
				ECS::MComponent<CPos>::get(pos.entity);
			if (!relativePos)
				continue;
			pos.x = pos.offsetX + relativePos->x;
			pos.y = pos.offsetY + relativePos->y;
		} else {
			auto speed = ECS::MComponent<CSpeed>::get(
				component.first);
			auto gravity = ECS::MComponent<CGravity>::get(
				component.first);

			if (!speed)
				continue;
			if (gravity) {
				speed->x += gravity->x * delta;
				speed->y += gravity->y * delta;
			}
			pos.x += speed->x * delta;
			pos.y += speed->y * delta;
		}

	}
}
