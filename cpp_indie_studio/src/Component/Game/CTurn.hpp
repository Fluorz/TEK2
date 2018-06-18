/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CTurn.hpp
*/


#ifndef INDIESTUDIO_CTURN_HPP
#define INDIESTUDIO_CTURN_HPP

#include <vector>
#include <map>
#include "Entity/Team/ETeam.hpp"
#include "Entity/Worms/EWorms.hpp"

class CTurn {
public:
	CTurn();
	~CTurn();
	void next();
	std::map<ECS::Entity, std::vector<ECS::Entity>> list;
	std::map<ECS::Entity, ECS::Entity> currentWorm;
	ECS::Entity currentTeam;
private:
	bool cleanTeam(ECS::Entity);
	bool nextWorm(ECS::Entity team);

};


#endif /* INDIESTUDIO_CTURN_HPP */
