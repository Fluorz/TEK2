/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CInventory.cpp
*/

#include "CInventory.hpp"

CInventory::CInventory()
{
	weaponList.emplace(Eweapon::BAZOOKA, 100);
	weaponList.emplace(Eweapon::GRENADE, 100);
	weaponList.emplace(Eweapon::SKY_STRIKER, 2);
}

CInventory::~CInventory()
{
	weaponList.clear();
}
