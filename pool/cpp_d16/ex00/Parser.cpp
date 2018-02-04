/*
** EPITECH PROJECT, 2018
** cpp_d16
** File description:
**        Parser.cpp
*/

#include <iostream>
#include "Parser.hpp"

Parser::Parser()
{
	_result = 0;
}

Parser::~Parser()
{
}

void	Parser::feed(const std::string &string)
{
	fillStack(std::string("(" + string + ")"));
}

int	Parser::result() const
{
	return (_result);
}

void	Parser::reset()
{
	_result = 0;
	std::stack<char> _tmp;
	std::stack<int> _tmpv;
	_operators = _tmp;
	_values = _tmpv;
}

void	doNothing()
{
}


void	Parser::fillStack(const std::string &operations)
{
	int tmp_result = _result;
	std::string values;
	int	nb_beforeStack = 0;
	unsigned int	i = 0;

	while (i != operations.size())
	{
		if (operations[i] >= '0' && operations[i] <= '9')
		{
			while (operations[i] >= '0' && operations[i] <= '9')
			{
				values += operations[i];
				i++;
			}
			nb_beforeStack = atoi(values.c_str());
			_values.push(nb_beforeStack);
			nb_beforeStack = 0;
			values.clear();
			i--;
		}
		else if (operations[i] == '*' || operations[i] == '+' || operations[i] == '-' || operations[i] == '/' || operations[i] == '%' || operations[i] == '(')
			_operators.push(operations[i]);
		else if (operations[i] == ')')
		{
			while (_operators.top() != '(')
			{
				int value_a = _values.top();
				_values.pop();
				int value_b = _values.top();
				_values.pop();
				if (_operators.top() == '+')
					_values.push(value_b + value_a);
				else if (_operators.top() == '-')
					_values.push(value_b - value_a);
				else if (_operators.top() == '*')
					_values.push(value_b * value_a);
				else if (_operators.top() == '/')
					_values.push(value_b / value_a);
				else if (_operators.top() == '%')
					_values.push(value_b % value_a);
				else
					break;
				_operators.pop();
			}
			_operators.pop();
		}
		else
			doNothing();
		i++;
	}
	_result = _values.top() + tmp_result;
}
