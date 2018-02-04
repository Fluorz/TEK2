/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
**        XML.cpp
*/

#include <iostream>
#include <sstream>
#include "XML.hpp"
#include "Toy.hpp"

#define stringify(name)

XML::XML()
{
}

XML::~XML()
{
}

std::string XML::Serialize(Object *obj)
{
	std::ostringstream ctn;

	ctn << "<object type=" << obj->_type << ">\n";
	if (obj->_type == TEDDY || obj->_type == LITTLEPONY) {

		ctn << "\t<name>" << "\n"
		<< "\t\t<p>" << ((Toy *)obj)->getname() << "</p>\n"
		<< "\t</name>\n";
	}
	ctn << "</object>";
	return ctn.str();
}
