/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CTimeScd.hpp
*/


#ifndef INDIESTUDIO_CTIMESCD_HPP
#define INDIESTUDIO_CTIMESCD_HPP

#include <ctime>

class CTimeScd {
public:
	CTimeScd(): id(0), last(std::time(nullptr)),
		 waiting(std::time(nullptr)) {};
	CTimeScd(int i, std::time_t l, std::time_t w) : id(i), last(l),
						      waiting(w) {};
	CTimeScd(int i): id(i), last(std::time(nullptr)),
		 waiting(std::time(nullptr)) {};
	~CTimeScd() = default;
	int id;
	std::time_t last;
	std::time_t waiting;
};

#endif //INDIESTUDIO_CTIMESCD_HPP
