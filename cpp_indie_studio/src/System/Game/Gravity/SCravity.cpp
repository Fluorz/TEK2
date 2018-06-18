/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SCravity.cpp
*/


#include "SCravity.hpp"

void SGravity::update(ECS::DeltaTime delta) {
	if (ECS::MComponent<CPos>::getAll().empty() ||
	    ECS::MComponent<CMap>::getAll().empty())
		return;
	auto map = ECS::MComponent<CMap>::getAll().begin()->second._map;
	for (auto itPos = ECS::MComponent<CPos>::getAll().begin();
	     itPos != ECS::MComponent<CPos>::getAll().end();
	     std::advance(itPos, 1)) {
		auto jump = ECS::MComponent<CJump>::get(itPos->first);
		if (!jump)
			continue;
		if (jump->jump != 0) {
			if (map.find(
				((int) itPos->second.x -
				 (int) itPos->second.x % 10) *
				10 + ((int) itPos->second.y + 12) / 10
			) == map.end() &&
			    map.find(
				    ((int) itPos->second.x + 5 -
				     (int) (itPos->second.x + 5) % 10) * 10 +
				    ((int) itPos->second.y + 12) / 10
			    ) == map.end()) {
				itPos->second.y += 2;
				jump->jump -= jump->jump < 7 ? 1 : 2;
			} else
				jump->jump = 0;
			continue;
		}
		float speed = 1.5;
		while (speed > 0) {
			if ((int) itPos->second.y % 10 != 0)
				itPos->second.y -= 0.1;
			else if (map.find(
				((int) itPos->second.x -
				 (int) itPos->second.x % 10) *
				10 + ((int) itPos->second.y - 10) / 10
			) == map.end() &&
				 map.find(
					 ((int) itPos->second.x + 5 -
					  (int) (itPos->second.x + 5) % 10) *
					 10 +
					 ((int) itPos->second.y - 10) / 10
				 ) == map.end())
				itPos->second.y -= 0.1;
			else
				speed = 0;
			speed -= 0.1;
		}
	}

}
