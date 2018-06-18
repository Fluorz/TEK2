/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** irrlichtComponent.hpp
*/


#ifndef INDIESTUDIO_IRRLICHTCOMPONENT_HPP
#define INDIESTUDIO_IRRLICHTCOMPONENT_HPP

#include <irrlicht.h>
#include <iostream>
#include "ECS/Event/MEvent.hpp"
#include "System/Scene/SScene.hpp"
#include "Events/EIrrlicht.hpp"
#include <vector>

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver() = default;

	virtual bool OnEvent(const irr::SEvent& event)
	{
		ECS::MEvent<EIrrlicht, irr::SEvent>::push(event);
		return false;
	}

};


class CIrrMain {
public:
	CIrrMain() = default;
	explicit CIrrMain(irr::IrrlichtDevice *dev)
		:device(dev), driver(device->getVideoDriver()),
		 env(device->getGUIEnvironment())
	{}
	irr::IrrlichtDevice * device;
	irr::video::IVideoDriver* driver;
	irr::gui::IGUIEnvironment* env;
};

class CScreenSize {
public:
	CScreenSize(): height(-1), width(-1) {}
	int height;
	int width;
};

class CImageTexture {
public:
	CImageTexture() : img(nullptr), id("") {};
	explicit CImageTexture(const std::string &path, std::string id_ = "");
	irr::video::ITexture *img;
	std::string id;
};

class CKeyIsDown {
public:
	CKeyIsDown() = default;
	bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif /* INDIESTUDIO_IRRLICHTCOMPONENT_HPP */
