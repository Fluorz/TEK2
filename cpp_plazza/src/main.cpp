/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        main.cpp
*/

#include <fstream>
#include <vector>
#include "plazza.hpp"
#include "plazzaInterface.hpp"
#include "processus.hpp"
#include "command.hpp"

void	callProcesses(PlazzaInterface &PlazzaI, std::vector<std::string> const &tasks)
{
	Processus masterProcess;

	PlazzaI.setTaskNumber(tasks.size());
	masterProcess.execCommandFromVector(tasks);
}

int	main(int ac, char **av)
{
	PlazzaInterface *PlazzaI = NULL;
	std::ostringstream ss;
	std::vector<std::string> tokens;
	std::vector<std::string> parsedTokens;

	if (ac != 2)
		return (84);
	PlazzaI = new PlazzaInterface(atoi(av[1]));
	ss << std::cin.rdbuf();
	PlazzaI->setCommandBuffer(ss.str());
	tokens = split(PlazzaI->getCommandBuffer(), "\n");
	parsedTokens = getParsedTokensVectorFromVector(tokens);
	callProcesses(*PlazzaI, parsedTokens);
	return (0);
}
