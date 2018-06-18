/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** FontTool.hpp
*/


#ifndef INDIESTUDIO_FONTTOOL_HPP
#define INDIESTUDIO_FONTTOOL_HPP

#include <vector>
#include <irrlicht.h>
#include "ECS/Component/MComponent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"

#define ABS(nb) (nb < 0 ? nb * -1 : nb)

enum FontSelectType {
	CLOSEST,
	CLOSEST_UP,
	CLOSEST_DOWN
};

enum DrawPosStart {
	CENTER,
	UP_RIGHT
};

class FontTool {
public:
	static FontTool &getInstance();

	FontTool(const FontTool &) = delete;

	FontTool &operator=(const FontTool &) = delete;

	static irr::gui::IGUIFont *getFont(const wchar_t *str, float rap,
					   bool Bold = false,
					   FontSelectType type = CLOSEST);

	static void
	draw(const wchar_t *str, float rap, irr::core::vector2d<irr::s32> Pos, irr::video::SColor color,
	     DrawPosStart start = CENTER, bool Bold = false,
	     FontSelectType type = CLOSEST);

	std::vector<irr::gui::IGUIFont *> fontList;
private:
	FontTool();

	~FontTool();
};


#endif /* INDIESTUDIO_FONTTOOL_HPP */
