/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** EPlayer.cpp
*/


#include "EPlayer.hpp"

ECS::Entity createPlayer()
{
	auto player = ECS::MEntity::create();
	auto KeyMapStaticList = ECS::MComponent<CKeyMapStatic>::getAll();
	auto KeyMapList = ECS::MComponent<CKeyMap>::getAll();

	if (KeyMapStaticList.empty())
		return (0);
	KeyMapList.size();
	auto it = KeyMapStaticList.begin();
	std::advance(it, KeyMapList.size());
	ECS::MComponent<CKeyMap>::create(player, CKeyMap(it->second));
	ECS::MComponent<CTeam>::create(player, CTeam(createTeam()));
}

void removePlayer(ECS::Entity player)
{
	ECS::MEntity::remove(player);
}