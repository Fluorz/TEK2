/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MSystem.hpp
*/


#ifndef INDIESTUDIO_MSYSTEM_HPP
#define INDIESTUDIO_MSYSTEM_HPP

#include <vector>
#include "ISystem.hpp"

namespace ECS {

	class MSystem {
	public:
		static MSystem &getInstance();

		MSystem(const MSystem &) = delete;
		MSystem &operator=(const MSystem &) = delete;

		static void add(SourceSystem *system);
		static void updateAll(DeltaTime delta);

	private:
		MSystem() = default;
		~MSystem() = default;

		std::vector<SourceSystem *> systems;
	};
}

#endif /* INDIESTUDIO_MSYSTEM_HPP */
