/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        split.cpp
*/

#include <vector>
#include "command.hpp"

bool endsWith(const std::string& s, const std::string& suffix)
{
	return s.size() >= suffix.size() &&
	s.substr(s.size() - suffix.size()) == suffix;
}

std::vector<std::string> split(const std::string& s,
const std::string& delimiter, const bool& removeEmptyEntries)
{
	std::vector<std::string> tokens;

	for (size_t start = 0, end; start < s.length(); start = end + delimiter.length()) {
		size_t position = s.find(delimiter, start);
		end = position != std::string::npos ? position : s.length();

		std::string token = s.substr(start, end - start);
		if (!removeEmptyEntries || !token.empty()) {
			tokens.push_back(token);
		}
	}
	if (!removeEmptyEntries &&
	(s.empty() || endsWith(s, delimiter))) {
		tokens.push_back("");
	}
	return tokens;
}
