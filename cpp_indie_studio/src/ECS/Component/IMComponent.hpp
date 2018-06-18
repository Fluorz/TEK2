/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IMComponent.hpp
*/


#ifndef INDIESTUDIO_IMCOMPONENT_HPP
#define INDIESTUDIO_IMCOMPONENT_HPP

namespace ECS {

	typedef unsigned long Entity;

	class IMComponent {
	public:
		virtual ~IMComponent() = default;
		IMComponent() = default;

		virtual void erase(Entity entity) = 0;

	private:
	};
}

#endif /* INDIESTUDIO_IMCOMPONENT_HPP */
