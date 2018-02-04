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
#include "WarpSystem.hpp"

namespace Federation
{
	namespace Starfleet
	{
		class Ship
		{
			public:
			Ship(int length, int width,
				 std::string name, short maxWarp);
			~Ship();
			void setupCore(WarpSystem::Core *);
			void checkCore();
			private:
			int _length;
			int _width;
			std :: string _name;
			short _maxWarp;
			WarpSystem::Core *_core;
		};
	}

	class Ship
	{
		public:
		Ship(int length , int width, std::string name);
		~Ship();
		void setupCore(WarpSystem::Core *);
		void checkCore();
		private:
		int _length;
		int _width;
		std :: string _name;
		short _maxWarp;
		WarpSystem::Core *_core;
	};
}

#endif
