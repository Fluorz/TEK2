/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** CName.hpp
*/


#ifndef INDIESTUDIO_CNAME_HPP
#define INDIESTUDIO_CNAME_HPP

#include <iostream>

class CName {
public:
	CName() : name("") {}
	CName(const std::string &n) : name(n) {}
	~CName() = default;
	std::string name;
};

#endif //INDIESTUDIO_CNAME_HPP
