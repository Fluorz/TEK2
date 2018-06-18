/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CJump.hpp
*/


#ifndef INDIESTUDIO_CJUMP_HPP
#define INDIESTUDIO_CJUMP_HPP

class CJump {
public:
	CJump() : jump(0) {};
	CJump(int j) : jump(j) {};
	~CJump() = default;
	int jump;
};

#endif //INDIESTUDIO_CJUMP_HPP
