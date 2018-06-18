/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CKeyMap.hpp
*/


#ifndef INDIESTUDIO_CKEYMAP_HPP
#define INDIESTUDIO_CKEYMAP_HPP

#include "CKeyMapStatic.hpp"

class CKeyMap {
public:
	CKeyMap() = default;
	CKeyMap(CKeyMapStatic &keymap) : KeyMap(keymap.KeyMap) {}
	~CKeyMap() = default;
	std::map<std::string, int> KeyMap;
};


#endif /* INDIESTUDIO_CKEYMAP_HPP */
