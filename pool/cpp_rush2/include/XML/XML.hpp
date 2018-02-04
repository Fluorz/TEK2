/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        XML.hpp
*/

#ifndef XML_HPP_
#define XML_HPP_

#include <string>
#include "Object.hpp"

class XML
{
public:
	XML();
	~XML();

	static std::string Serialize(Object *);
};

#endif
