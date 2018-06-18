/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SKill.cpp
*/


#include <Component/Game/CTimeScd.hpp>
#include <Component/Game/CGameStatus.hpp>
#include "SKill.hpp"

static ECS::Entity findPlayer(ECS::Entity team)
{
	auto PlayerIt = ECS::MComponent<CKeyMap>::getAll().begin();
	while (PlayerIt != ECS::MComponent<CKeyMap>::getAll().end()) {
		if (ECS::MComponent<CTeam>::get(PlayerIt->first)->team == team)
			return PlayerIt->first;
		std::advance(PlayerIt, 1);
	}
	return (0);
}

static void CTurnCleanTeam(ECS::Entity team)
{
	auto &turn = ECS::MComponent<CTurn>::getAll().begin()->second;
	auto &wormsL = turn.list.at(team);

	if (wormsL.size() <= 1)
		return;
	if (turn.currentTeam == team) {
		auto it = turn.list.find(team);
		std::advance(it, 1);
		if (it == turn.list.end())
			it = turn.list.begin();
		turn.currentTeam = it->first;
	}
	turn.list.erase(turn.list.find(team));
	turn.currentWorm.erase(turn.currentWorm.find(team));
}

static void clean_munition()
{
	if (ECS::MComponent<CMuntion>::getAll().empty())
		return;
	for (auto it = ECS::MComponent<CMuntion>::getAll().begin();
	     it != ECS::MComponent<CMuntion>::getAll().end();
	     std::advance(it, 1)) {
		if (it->second.node)
			it->second.node = nullptr;
	}
	ECS::MComponent<CSceneNode>::getAll().begin()
		->second.munitionNode->removeAll();
}

static void CTurnCleanWorm(ECS::Entity worm, ECS::Entity team)
{
	auto &turn = ECS::MComponent<CTurn>::getAll().begin()->second;
	auto &wormsL = turn.list.at(team);

	if (team == turn.currentTeam && worm == turn.currentWorm.at(team)) {
		while (!ECS::MComponent<CMuntion>::getAll().empty())
			ECS::MComponent<CMuntion>::remove
			(ECS::MComponent<CMuntion>::getAll().begin()->first);
		clean_munition();
		clean_weapon();
		auto &timeList = ECS::MComponent<CTimeScd>::getAll();
		CTimeScd *timeGame = nullptr;

		for (auto it = timeList.begin(); it != timeList.end();
		     std::advance(it, 1))
			if (it->second.id == id_time::TIME_GAME)
				timeGame = &(it->second);
		if (!timeGame)
			return;
		timeGame->waiting = std::time(nullptr) + 5;
		auto &status = ECS::MComponent<CGameStatus>::
		        getAll().begin()->second;
		status.wait = true;
	}
	if (wormsL.size() <= 1) {
		return;
	}
	if (turn.currentWorm.at(team) == worm) {
		auto it = wormsL.begin();
		while (it != wormsL.end() && *it != worm)
			std::advance(it, 1);
		if (it != wormsL.end()) {
			std::advance(it, 1);
			if (it == wormsL.end())
				it = wormsL.begin();
			turn.currentWorm.at(team) = *it;
		}
	}
	auto it = wormsL.begin();
	while (it != wormsL.end() && *it != worm)
		std::advance(it, 1);
	if (it != wormsL.end()) {

		wormsL.erase(it);
	}
}

void SKill::update(ECS::DeltaTime delta)
{
	std::map<ECS::Entity , int> alive;
	auto lifeList = ECS::MComponent<CLife>::getAll();
	for (auto it = lifeList.begin(); it != lifeList.end();
		std::advance(it, 1)) {
		auto team = ECS::MComponent<CTeam>::get(it->first)->team;
		if (it->second.life == 0) {
			CTurnCleanWorm(it->first, team);
			removeWorms(it->first);
			if (alive.find(team) == alive.end())
				alive.emplace(team, 0);
		} else {
			if (alive.find(team) == alive.end())
				alive.emplace(team, 1);
			else
				alive.at(team) += 1;
		}
	}
	for (auto it = alive.begin(); it != alive.end(); std::advance(it, 1)) {
		if (it->second == 0) {
			if (findPlayer(it->first))
				removePlayer(findPlayer(it->first));
			CTurnCleanTeam(it->first);
			removeTeam(it->first);
		}
	}
}
