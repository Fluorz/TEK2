/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MComponent.hpp
*/


#ifndef INDIESTUDIO_MCOMPONENT_HPP
#define INDIESTUDIO_MCOMPONENT_HPP

#include <map>
#include <ECS/Entity/MEntity.hpp>
#include "IMComponent.hpp"

namespace ECS {

	template<class T>
	class MComponent : public IMComponent {
	public:
		~MComponent() override = default;

		static MComponent &getInstance()
		{
			static MComponent instance;
			return instance;
		}

		MComponent(const MComponent &) = delete;
		MComponent &operator=(const MComponent &) = delete;

		static void create(Entity entity, T component)
		{
			MEntity::addComponent(entity, &getInstance());
			getInstance().pool[entity] = component;
		}

		static T *get(Entity entity)
		{
			auto &instance = getInstance();
			if (instance.pool.find(entity) == instance.pool.end())
				return nullptr;
			return &instance.pool[entity];
		}

		static std::map<Entity, T> &getAll()
		{
			return getInstance().pool;
		}

		void erase(Entity entity) override
		{
			pool.erase(entity);
		}

		static void remove(Entity entity)
		{
			MEntity::removeComponent(entity, &getInstance());
			getInstance().erase(entity);
		}

	private:
		MComponent() = default;

		std::map<Entity, T> pool;
	};
}

#endif /* INDIESTUDIO_MCOMPONENT_HPP */

