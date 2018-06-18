/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        scrapper.cpp
*/

#include <fstream>
#include <iostream>
#include <string.h>
#include <regex>
#include "communication.hpp"

void 	findPhoneNumber(std::string contenu)
{
	std::smatch match;
	std::regex expr("(([0-9]{2})(([\" \"|0-9]){8,12}))");

	while (std::regex_search(contenu, match, expr)) {
		std::cout << match[1].str() << std::endl;
		contenu = match.suffix();
	}
}

void 	findEmailAddress(std::string contenu)
{
	std::smatch match;
	std::regex expr("(([a-zA-Z0-9_.-]+)([@])([a-zA-Z0-9_-]+)[.]([a-zA-Z]{2,10}))");

	while (std::regex_search(contenu, match, expr)) {
		std::cout << match[1].str() << std::endl;
		contenu = match.suffix();
	}
}

void 	findIpAddress(std::string contenu)
{
	std::smatch match;
	std::regex expr("([0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3})");

	while (std::regex_search(contenu, match, expr)) {
		std::cout << match[1].str() << std::endl;
		contenu = match.suffix();
	}
}

void 	findData(Information _information, std::string contenu)
{
	switch (_information) {
		case PHONE_NUMBER:
		findPhoneNumber(contenu);
		break;
		case EMAIL_ADDRESS:
		findEmailAddress(contenu);
		break;
		case IP_ADDRESS:
		findIpAddress(contenu);
		break;
	}
}

void 	scrapper(std::string file, Information _information)
{
	std::string contenu;
	std::ifstream fichier(file, std::ios::in);
	
	if(fichier)
	{
		while (getline(fichier, contenu))
			findData(_information, contenu);
		fichier.close();
	}
	else
		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

}