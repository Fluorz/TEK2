/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        processus.cpp
*/

#include <string>
#include <vector>
#include "communication.hpp"
#include "processus.hpp"

Processus::Processus()
{

}

Processus::~Processus()
{
	
}

std::vector<std::string> split(const std::string& s,
const std::string& delimiter, const bool& removeEmptyEntries = false);
void 	scrapper(std::string file, Information _information);

void Processus::execCommandFromVector(std::vector<std::string> tokens)
{
	Information type;
	std::vector<std::string> tmpToken;

	for (std::vector<std::string>::iterator token = tokens.begin();
	token != tokens.end(); token++) {
		tmpToken = split(*token, " ");
		if (!tmpToken[1].compare("EMAIL_ADDRESS")) {
			type = EMAIL_ADDRESS;
		}
		else if (!tmpToken[1].compare("PHONE_NUMBER")) {
			type = PHONE_NUMBER;
		}
		else
			type = IP_ADDRESS;
		scrapper(tmpToken[0], type);
	}
}
