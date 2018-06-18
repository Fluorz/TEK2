/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SFallDamage.cpp
*/


#include "SFallDamage.hpp"

void SFallDamage::update(ECS::DeltaTime delta)
{
	if (ECS::MComponent<CPos>::getAll().empty() ||
	    ECS::MComponent<CMap>::getAll().empty())
		return;
	auto map = ECS::MComponent<CMap>::getAll().begin()->second._map;
	for (auto itPos = ECS::MComponent<CPos>::getAll().begin();
	     itPos != ECS::MComponent<CPos>::getAll().end();
	     std::advance(itPos, 1)) {
		auto fall = ECS::MComponent<CFall>::get(itPos->first);
		if (!fall)
			continue;
		if (map.find(
			((int) itPos->second.x - (int) itPos->second.x % 10) *
			10 + ((int) itPos->second.y - 10) / 10
		) == map.end()) {
			if (fall->fall == 0 || fall->fall < (int)itPos->second.y)
				fall->fall = (int)itPos->second.y;
		} else {
			if (fall->fall != 0) {
				int diff = fall->fall - (int)itPos->second.y;
				diff -= 40;
				if (diff > 0)
					wormDamage(itPos->first, diff / 10 * 4);
			}
			fall->fall = 0;
		}
		if (itPos->second.y < 0 || itPos->second.x < -50 ||
		        itPos->second.x > 550)
			wormDamage(itPos->first, 100);
	}
}
