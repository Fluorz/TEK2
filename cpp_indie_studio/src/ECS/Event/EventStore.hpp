/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** EventStore.hpp
*/


#ifndef INDIESTUDIO_EVENTSTORE_HPP
#define INDIESTUDIO_EVENTSTORE_HPP

#include <vector>
#include "IMEvent.hpp"

namespace ECS {

	class EventStore {
	public:
		static EventStore &getInstance()
		{
			static EventStore instance;
			return instance;
		}

		EventStore(const EventStore &) = delete;
		EventStore &operator=(const EventStore &) = delete;

		static void store(IMEvent *event);
		static void clearAll();

	private:
		EventStore() = default;
		~EventStore() = default;

		std::vector<IMEvent *> pool;
	};
}

#endif /* INDIESTUDIO_EVENTSTORE_HPP */
