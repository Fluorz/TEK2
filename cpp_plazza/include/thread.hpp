/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        thread.hpp
*/

#ifndef THREAD_HPP_
# define THREAD_HPP_

#include <pthread.h>

class CThread
{
	public:
		CThread();
		virtual ~CThread();

		void start();
		void join();
	private:
		void createThread();
		void threadFunc(void *);
		pthread_t _thread;
};

#endif