/*
** EPITECH PROJECT, 2018
** cpp_d16
** File description:
**        Parser.hpp
*/

#ifndef _PARSER_
# define _PARSER_

#include <string>
#include <cctype>
#include <stack>

class Parser
{
public:
	Parser();
	~Parser();
	void feed(const std::string &string);
	int result() const;
	void reset();
	void fillStack(const std::string &operations);
	void executeStack() const;
private:
	int	_result;
	std::stack<char> _operators;
	std::stack<int> _values;
};

void	doNothing();
#endif
