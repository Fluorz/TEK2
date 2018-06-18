/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CColor.hpp
*/


#ifndef INDIESTUDIO_CCOLOR_HPP
#define INDIESTUDIO_CCOLOR_HPP

#include <irrlicht.h>

class CColor {
public:
	CColor() = default;
	CColor(irr::video::SColor color_) : color(color_) {}
	~CColor() = default;
	irr::video::SColor color;
};


#endif /* INDIESTUDIO_CCOLOR_HPP */
