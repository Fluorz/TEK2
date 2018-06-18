/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CMovement.hpp
*/


#ifndef INDIESTUDIO_CMOVEMENT_HPP
#define INDIESTUDIO_CMOVEMENT_HPP

class CMovement {
public:
	CMovement() : X(0), Y(0) {};
	CMovement(float x, float y) : X(x), Y(y) {};
	~CMovement() {};
	float X;
	float Y;
};

#endif //INDIESTUDIO_CMOVEMENT_HPP
