/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CMesh.hpp
*/


#ifndef INDIESTUDIO_CMESH_HPP
#define INDIESTUDIO_CMESH_HPP

#include <irrlicht.h>
#include <map>
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "ECS/Component/MComponent.hpp"

enum id_mesh {
	MESH_BAZOOKA,
	MESH_BOMB,
	MESH_BOMB_LAUNCHER,
	MESH_PALM,
	MESH_PENGUIN,
	MESH_ROCKET
};

enum id_mesh_texture {
	TEXTURE_BAZOOKA,
	TEXTURE_BOMB,
	TEXTURE_BOMB_LAUNCHER,
	TEXTURE_PALM,
	TEXTURE_PENGUIN,
	TEXTURE_ROCKET
};

class CMesh {
public:
	CMesh();
	~CMesh();
	std::map<int, irr::scene::IAnimatedMesh *> meshMap;
	std::map<int, irr::video::ITexture *> meshTexture;
};


#endif /* INDIESTUDIO_CMESH_HPP */
