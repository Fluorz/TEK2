/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Gravity.hpp
*/


#ifndef INDIESTUDIO_GRAVITY_HPP
#define INDIESTUDIO_GRAVITY_HPP

class CGravity {
public:
	CGravity() = default;
	~CGravity() = default;

	CGravity(float x, float y)
		: x(x), y(y)
	{};

	float x;
	float y;

private:
};

#endif //INDIESTUDIO_GRAVITY_HPP
