/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CTime.hpp
*/


#ifndef INDIESTUDIO_CTIME_HPP
#define INDIESTUDIO_CTIME_HPP

#include <time.h>

class CTime {
public:
	CTime(): id(0), last(clock()),
		 waiting(clock()) {};
	CTime(int i, clock_t l, clock_t w) : id(i), last(l),
						      waiting(w) {};
	CTime(int i): id(i), last(clock()),
		 waiting(clock()) {};
	~CTime() = default;
	int id;
	clock_t last;
	clock_t waiting;
};

#endif //INDIESTUDIO_CTIME_HPP
