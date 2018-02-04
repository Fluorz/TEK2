/*
** EPITECH PROJECT, 2018
** cpp_d07m
** File description:
**        Borg.hpp
*/

#ifndef _BORG_
# define _BORG_

#include <iostream>
#include <cctype>
#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Destination.hpp"

namespace Federation
{
	namespace Starfleet
	{
		class Captain;
		class Ship;
		class Ensign;
	}
	class Ship;
}

namespace Borg
{
	class Ship
	{
		public:
		Ship(int weaponFrequency, short repair);
		Ship(int weaponFrequency);
		~Ship();
		void setupCore(WarpSystem::Core *);
		void checkCore();
		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();
		int getShield () ;
		void setShield (int shield);
		int getWeaponFrequency ();
		void setWeaponFrequency (int frequency);
		short getRepair ();
		void setRepair (short repair);
		void fire(Federation::Starfleet::Ship *target);
		void fire(Federation::Ship *target);
		void repair();
		private:
		int _shield;
		int _weaponFrequency;
		short _repair;
		int _side;
		short _maxWarp;
		WarpSystem::Core *_core;
		Destination _location;
		Destination _home;
	};
}

#endif
