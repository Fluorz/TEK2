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
				std::string name, short maxWarp);
			~Ship();
			void setupCore(WarpSystem::Core *);
			void checkCore();
			void promote(Captain*);
			private:
			int _length;
			int _width;
			std::string _name;
			short _maxWarp;
			WarpSystem::Core *_core;
			Captain *_Captain;
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
		private:
		int _length;
		int _width;
		std :: string _name;
		short _maxWarp;
		WarpSystem::Core *_core;
	};
}

#endif
