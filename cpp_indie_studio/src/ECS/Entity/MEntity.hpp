/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Entity.hpp
*/


#ifndef INDIESTUDIO_ENTITY_HPP
#define INDIESTUDIO_ENTITY_HPP

#include <map>
#include <vector>
#include <ECS/Component/IMComponent.hpp>

namespace ECS {

	typedef unsigned long Entity;

	class MEntity {
	public:
		static MEntity &getInstance();

		MEntity(const MEntity &) = delete;
		MEntity &operator=(const MEntity &) = delete;

		static Entity create();
		static void remove(Entity entity);

		static void addComponent(Entity entity, IMComponent *component);
		static void removeComponent(Entity entity , IMComponent *component);

		MEntity() = default;

	private:
		~MEntity() = default;

		std::map<Entity, std::vector<IMComponent *>> entities;

		unsigned long last{0};
	};
}

#endif /* INDIESTUDIO_ENTITY_HPP */
