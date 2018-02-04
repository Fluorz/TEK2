/*
** EPITECH PROJECT, 2018
** cpp_d07m
** File description:
**        Federation.hpp
*/

#ifndef _FEDERATION_
# define _FEDERATION_

#include <iostream>
#include <cctype>
#include "Borg.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
	class Ship;
}

namespace Federation
{

	namespace Starfleet
	{
		class Captain
		{
			public:
			Captain(std::string);
			~Captain();
			std::string getName();
			int getAge();
			void setAge(int age);
			private:
			std::string _name;
			int	_age;
		};

		class Ship
		{
			public:
			Ship(int length, int width,
				std::string name, short maxWarp, int);
			Ship();
			~Ship();
			void setupCore(WarpSystem::Core *);
			void checkCore();
			void promote(Captain*);
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
			int getShield();
			void setShield (int shield);
			int getTorpedo();
			void setTorpedo(int torpedo);
			void fire(Borg::Ship *target);
			void fire(int torpedoes, Borg::Ship *target);
			private:
			int _shield;
			int _length;
			int _width;
			std :: string _name;
			short _maxWarp;
			WarpSystem::Core *_core;
			Captain *_Captain;
			Destination _location;
			Destination _home;
			int _photonTorpedo;
		};

		class Ensign
		{
			public:
			Ensign(std::string);
			~Ensign();
			private:
			std::string _name;
		};

	}

	class Ship
	{
		public:
		Ship(int length, int width, std::string name);
		~Ship();
		void setupCore(WarpSystem::Core *);
		void checkCore();
		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();
		WarpSystem::Core *getCore();
		private:
		WarpSystem::Core *_core;
		int _length;
		int _width;
		std :: string _name;
		short _maxWarp;
		Destination _location;
		Destination _home;
	};
}

#endif
