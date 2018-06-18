/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CTurn.cpp
*/


#include "CTurn.hpp"

CTurn::CTurn()
{
	if (ECS::MComponent<CInventory>::getAll().empty())
		return;
	if (ECS::MComponent<CName>::getAll().empty())
		return;
	for (auto it = ECS::MComponent<CInventory>::getAll().begin();
		it != ECS::MComponent<CInventory>::getAll().end();
		std::advance(it, 1)) {
		list.emplace(it->first, std::vector<ECS::Entity>{});
	}
	for (auto it = ECS::MComponent<CName>::getAll().begin();
		it != ECS::MComponent<CName>::getAll().end();
		std::advance(it, 1)) {
		ECS::Entity team = ECS::MComponent<CTeam>::get(it->first)->team;
		list.at(team).emplace_back(it->first);
	}
	currentTeam = list.begin()->first;
	for (auto it = list.begin(); it != list.end(); std::advance(it, 1))
		currentWorm.emplace(it->first, *(it->second.begin()));
//	auto it = list.begin();
//	while (it != list.end()) {
//		auto itCurWor = currentWorm.find(it->first);
//		std::cout << "Team ID : " << it->first << std::endl;
//		for (auto it2 = it->second.begin(); it2 != it->second.end(); std::advance(it2, 1))
//			std::cout << *it2 << " - ";
//		std::cout << std::endl << "Current : " << itCurWor->second << std::endl << std::endl;
//		std::advance(it, 1);
//	}
}

CTurn::~CTurn() {}

void CTurn::next()
{
	auto it = list.begin();
	while (it != list.end()) {
		auto itCurWor = currentWorm.find(it->first);
		std::cout << "Team ID : " << it->first << std::endl;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); std::advance(it2, 1))
			std::cout << *it2 << " - ";
		std::cout << std::endl << "Current : " << itCurWor->second << std::endl << std::endl;
		std::advance(it, 1);
	}
	auto itTeam = list.find(currentTeam);
	if (itTeam == list.end() || list.size() <= 1)
		return;
	ECS::Entity nextTeam = currentTeam;
	std::advance(itTeam, 1);
	if (itTeam == list.end())
		itTeam = list.begin();
	while (!list.empty() && itTeam->first != list.find(currentTeam)->first && itTeam != list.end()) {
		if (nextTeam == currentTeam)
			nextTeam = itTeam->first;
		std::advance(itTeam, 1);
		if (itTeam == list.end())
			itTeam = list.begin();
	}
	nextWorm(currentTeam);
	currentTeam = nextTeam;

}

bool CTurn::cleanTeam(ECS::Entity team)
{
	auto WormList = list.at(team);
	auto itWorm = WormList.begin();
	if (itWorm == WormList.end())
		return false;
	ECS::Entity curWorm = currentWorm.at(team);
	ECS::Entity nextWorm = curWorm;

	while (itWorm != WormList.end() && *itWorm != curWorm) {
		std::advance(itWorm, 1);
	}
	if (itWorm == WormList.end())
		return false;

	auto itSave = itWorm;
	std::advance(itWorm, 1);
	if (itWorm == WormList.end())
		itWorm = WormList.begin();
	while (itWorm != itSave) {

		if (!ECS::MComponent<CName>::get(*itWorm)) {
			auto itDel = itWorm;
			std::advance(itWorm, 1);
			WormList.erase(itDel);
			continue;
		}
		if (nextWorm != curWorm)
			nextWorm = *itWorm;
		std::advance(itWorm, 1);
		if (itWorm == WormList.end())
			itWorm = WormList.begin();
	}
	if (!ECS::MComponent<CName>::get(*itSave))
		WormList.erase(itSave);
	if (!ECS::MComponent<CName>::get(curWorm))
		currentWorm.find(team)->second = nextWorm;
	return false;
}

bool CTurn::nextWorm(ECS::Entity team)
{
	ECS::Entity curWorm = currentWorm.at(team);
	auto wormList = list.at(team);
	auto it = wormList.begin();
	while (it != wormList.end()) {
		if (*it == curWorm)
			break;
		std::advance(it, 1);
	}
	if (it == wormList.end())
		currentWorm.find(team)->second = *(wormList.begin());
	else {
		std::advance(it, 1);
		if (it == wormList.end())
			it = wormList.begin();
		currentWorm.find(team)->second = *(it);
	}
	return false;
}
