/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** ETeam
*/

#include "ETeam.hpp"

ECS::Entity createTeam()
{
	static irr::video::SColor colorList[] = {
		{255, 0, 0, 255},
		{255, 255, 0, 0},
		{255, 0, 255, 0},
		{255, 255, 255, 0}
	};
	auto team = ECS::MEntity::create();
	auto teamList = ECS::MComponent<CInventory>::getAll();
	ECS::MComponent<CColor>::create(team, colorList[teamList.size()]);
	ECS::MComponent<CInventory>::create(team, CInventory());
	createWorms(team);
	createWorms(team);
	createWorms(team);
	createWorms(team);
	return team;
}

void removeTeam(ECS::Entity team)
{
	ECS::MEntity::remove(team);
}