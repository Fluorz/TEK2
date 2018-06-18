/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MEvent.hpp
*/


#ifndef INDIESTUDIO_MEVENT_HPP
#define INDIESTUDIO_MEVENT_HPP

#include <vector>
#include "EventStore.hpp"
#include "IMEvent.hpp"

namespace ECS {

	template<class Type, typename Data>
	class MEvent : public IMEvent {
	public:
		typedef struct {
			Data data;
			bool active;
		} event_t;

		static MEvent &getInstance()
		{
			static MEvent instance;
			return instance;
		}

		MEvent(const MEvent &) = delete;
		MEvent &operator=(const MEvent &) = delete;

		static bool empty()
		{
			return getInstance().pool.empty();
		}

		static void push(Data event)
		{
			getInstance().pool.push_back({event, true});
		}

		static bool pop(Data &event)
		{
			auto &instance = getInstance();
			if (empty())
				return false;
			event = instance.pool.front().data;
			instance.pool.erase(instance.pool.begin());
			return true;
		}

		void clear() override
		{
			Data event;
			for (unsigned int i = 0; i < pool.size();) {
				if (!pool[i].active) {
					pop(event);
				} else {
					pool[i].active = false;
					i++;
				}
			}
		}

	private:
		MEvent()
		{
			EventStore::store(this);
		}

		~MEvent() override = default;

		std::vector<event_t> pool;
	};
}

#endif /* INDIESTUDIO_MEVENT_HPP */
