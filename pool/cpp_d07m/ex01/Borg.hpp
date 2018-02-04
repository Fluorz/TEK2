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

namespace Borg
{
	class Ship
	{
		public:
		Ship();
		~Ship();
		void setupCore(WarpSystem::Core *);
		void checkCore();
		private:
		int _side;
		short _maxWarp;
		WarpSystem::Core *_core;
	};
}

#endif
