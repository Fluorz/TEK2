/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CTeam.hpp
*/


#ifndef INDIESTUDIO_CTEAM_HPP
#define INDIESTUDIO_CTEAM_HPP

#include "ECS/Entity/MEntity.hpp"
#include "Entity/Team/ETeam.hpp"

class CTeam {
public:
	CTeam() : team(0) {};
	CTeam(ECS::Entity team_) : team(team_) {};
	~CTeam() = default;
	ECS::Entity team;
};


#endif /* INDIESTUDIO_CTEAM_HPP */
