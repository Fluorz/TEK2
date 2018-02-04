/*
** EPITECH PROJECT, 2018
** cpp_d13
** File description:
**        Picture.hpp
*/

#ifndef _PICTURE_
# define _PICTURE_

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

class Picture
{
public:
	Picture();
	Picture(const Picture&);
	Picture &operator=(const Picture&);
	Picture(const std::string &file);
	~Picture();
	bool getPictureFromFile(const std::string &file);
	std::string getData() const;
	std::string data;

};

#endif
