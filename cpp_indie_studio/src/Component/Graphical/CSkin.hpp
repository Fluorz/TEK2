/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CSkin.hpp
*/


#ifndef INDIESTUDIO_CSKIN_HPP
#define INDIESTUDIO_CSKIN_HPP

#include <irrlicht.h>

class CSkin {
public:
	CSkin() = default;
	CSkin(irr::scene::IAnimatedMeshSceneNode* node_) : node(node_) {};
	~CSkin() = default;
	irr::scene::IAnimatedMeshSceneNode* node;
};


#endif /* INDIESTUDIO_CSKIN_HPP */
