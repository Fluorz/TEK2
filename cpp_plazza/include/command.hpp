/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        command.hpp
*/

#ifndef __COMMAND__
# define __COMMAND__

#include <fstream>
#include <vector>
#include <string>

bool endsWith(const std::string& s, const std::string& suffix);
std::vector<std::string> split(const std::string& s,
const std::string& delimiter, const bool& removeEmptyEntries = false);
bool is_enum(std::string &str);
std::vector<std::string> sanitizeTokens(std::vector<std::string> &tokens);
std::vector<std::string> getCommandsFromVector(std::vector<std::string> &cmds);
std::vector<std::string> getParsedTokensVectorFromVector(std::vector<std::string> tokens);

#endif
