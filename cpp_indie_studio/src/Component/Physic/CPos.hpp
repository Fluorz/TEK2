/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CPos.hpp
*/


#ifndef INDIESTUDIO_CPOS_HPP
#define INDIESTUDIO_CPOS_HPP


#include <ECS/Entity/MEntity.hpp>

class CPos {
public:
	CPos() = default;
	~CPos() = default;

	CPos(float offsetX, float offsetY, ECS::Entity entity)
		: x(0), y(0), relative(true), entity(entity),
		  offsetX(offsetX), offsetY(offsetY)
	{}

	CPos(float x, float y)
		: x(x), y(y), relative(false), entity(0), offsetX(0), offsetY(0)
	{};

	float x;
	float y;

	bool relative;
	ECS::Entity entity;
	float offsetX;
	float offsetY;

private:
};


#endif /* INDIESTUDIO_CPOS_HPP */
