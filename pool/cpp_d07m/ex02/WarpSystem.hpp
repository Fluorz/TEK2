/*
** EPITECH PROJECT, 2018
** cpp_d07m
** File description:
**        WarpSystem.hpp
*/

#ifndef _WARPSYSTEM_
# define _WARPSYSTEM_

#include <iostream>
#include <cctype>

namespace WarpSystem
{
	class QuantumReactor
	{
		public:
		QuantumReactor();
		~QuantumReactor();
		bool	isStable();
		void	setStability(bool _stability);
		private:
		bool _stability;
	};

	class Core
	{
		public:
		Core(QuantumReactor *);
		~Core();
		QuantumReactor *checkReactor();
		private:
		QuantumReactor *_coreReactor;
	};
}

#endif
