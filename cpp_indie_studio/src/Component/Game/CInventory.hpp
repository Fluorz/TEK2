/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CInventory.hpp
*/


#ifndef INDIESTUDIO_CINVENTORY_HPP
#define INDIESTUDIO_CINVENTORY_HPP

#include <map>
#include "Entity/Weapon/EWeapon.hpp"
#include "ECS/Entity/MEntity.hpp"
#include "Component/Game/CWeapon.hpp"

class CInventory {
public:
	CInventory();
	~CInventory();
	std::map<Eweapon , unsigned int> weaponList;
};


#endif /* INDIESTUDIO_CINVENTORY_HPP */
