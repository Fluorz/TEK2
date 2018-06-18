/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CGameStatus.hpp
*/


#ifndef INDIESTUDIO_CGAMESTATUS_HPP
#define INDIESTUDIO_CGAMESTATUS_HPP

class CGameStatus {
public:
	CGameStatus() : degat(false), start(true), wait(true), game(false) {};
	~CGameStatus() = default;
	bool degat;
	bool wait;
	bool start;
	bool game;
};

#endif //INDIESTUDIO_CGAMESTATUS_HPP
