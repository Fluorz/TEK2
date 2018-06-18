/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IMEvent.hpp
*/


#ifndef INDIESTUDIO_IMEVENT_HPP
#define INDIESTUDIO_IMEVENT_HPP

namespace ECS {

	class IMEvent {
	public:
		IMEvent() = default;
		virtual ~IMEvent() = default;

		virtual void clear() = 0;

	private:
	};
}


#endif /* INDIESTUDIO_IMEVENT_HPP */
