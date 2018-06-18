/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CKeyMapStatic.hpp
*/


#ifndef INDIESTUDIO_CKEYMAPSTATIC_HPP
#define INDIESTUDIO_CKEYMAPSTATIC_HPP

#include <irrlicht.h>
#include <map>

class CKeyMapStatic {
public:
	CKeyMapStatic();
	~CKeyMapStatic() = default;
	std::map<std::string, int> KeyMap;
	std::map<std::string, int> ButtonCode;
	std::string waiting;
};


#endif /* INDIESTUDIO_CKEYMAPSTATIC_HPP */
