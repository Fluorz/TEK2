/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        commands.cpp
*/

#include <fstream>
#include <sstream>
#include <vector>
#include "command.hpp"

bool is_enum(std::string &str)
{
	if (!str.compare("PHONE_NUMBER") || !str.compare("EMAIL_ADDRESS") ||
		!str.compare("IP_ADDRESS"))
		return (true);
	return (false);
}

std::vector<std::string> sanitizeTokens(std::vector<std::string> &tokens)
{
	std::vector<std::string> sanitized;
	for (std::vector<std::string>::iterator token = tokens.begin();
		token != tokens.end(); token++) {
		if ((*token).length() > 0) {
			sanitized.push_back(*token);
		}
	}
	return (sanitized);
}

std::vector<std::string> getCommandsFromVector(std::vector<std::string> &cmds)
{
	std::vector<std::string> tokens;
	std::vector<std::string> tmpTokens;
	std::string tempString;
	std::stringstream ss;

	for (std::vector<std::string>::iterator token = cmds.begin();
		token != cmds.end(); token++) {
		tempString = *token;
		tmpTokens = split(tempString, " ");
		tmpTokens = sanitizeTokens(tmpTokens);
		for (std::vector<std::string>::iterator file = tmpTokens.begin();
			file != tmpTokens.end() && !is_enum(*file); file++) {
			ss.str("");
			ss << *file << " " << tmpTokens.back();
			tokens.push_back(ss.str());
		}
	}
	return (tokens);
}

std::vector<std::string> getParsedTokensVectorFromVector(std::vector<std::string> tokens)
{
	std::vector<std::string> tempToken;
	std::vector<std::string> newLineSepTokens;
	std::vector<std::string> colonSepTokens;
	std::vector<std::string> parsedTokens;

	for (std::vector<std::string>::iterator token = tokens.begin(); token != tokens.end(); token++) {
		if (!(*token).compare(""))
			continue;
		newLineSepTokens.push_back(*token);
	}
	for (std::vector<std::string>::iterator token = newLineSepTokens.begin(); token != newLineSepTokens.end(); token++) {
		tempToken = split(*token, ";");
		for (std::vector<std::string>::iterator subToken = tempToken.begin(); subToken != tempToken.end(); subToken++)
			colonSepTokens.push_back(*subToken);
	}
	parsedTokens = getCommandsFromVector(colonSepTokens);
	return (parsedTokens);
}