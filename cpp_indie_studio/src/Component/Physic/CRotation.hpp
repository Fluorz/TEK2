/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CRotation.hpp
*/


#ifndef INDIESTUDIO_CROTATION_HPP
#define INDIESTUDIO_CROTATION_HPP

class CRotation {
public:
	CRotation() : dir(0), aim(0) {};
	~CRotation() = default;
	CRotation(float x, float y) : dir(x), aim(y) {};
	float aim;
	float dir;
};

#endif //INDIESTUDIO_CROTATION_HPP
