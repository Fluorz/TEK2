/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** EventStore.cpp
*/


#include "EventStore.hpp"

void ECS::EventStore::store(ECS::IMEvent *event)
{
	getInstance().pool.push_back(event);
}

void ECS::EventStore::clearAll()
{
	for (auto *mEvent : getInstance().pool)
		mEvent->clear();
}
