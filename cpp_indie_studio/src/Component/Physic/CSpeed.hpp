/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CSpeed.hpp
*/


#ifndef INDIESTUDIO_CSPEED_HPP
#define INDIESTUDIO_CSPEED_HPP


class CSpeed {
public:
	CSpeed() = default;
	~CSpeed() = default;

	CSpeed(float x, float y)
		: x(x), y(y)
	{};

	float x;
	float y;

private:
};


#endif /* INDIESTUDIO_CSPEED_HPP */
