/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CLife.hpp
*/


#ifndef INDIESTUDIO_CLIFE_HPP
#define INDIESTUDIO_CLIFE_HPP

class CLife {
public:
	CLife() : life(100) {}
	explicit CLife(int l) : life(l) {}
	~CLife() = default;
	int life;
};

#endif //INDIESTUDIO_CLIFE_HPP
