/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        temp_conversion.cpp
*/

#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

void	printPrecision(double value, const char *str)
{
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std:: ios::floatfield);
	std::cout << std::setw(16);
	std::cout << value;
	std::cout << std::setw(16);
	std::cout << str;
	std::cout << '\n';
}

int	main(void)
{
	double	value = 0;
	int i = 0;
	std::string line;
	std::string arr[4];

	getline(std::cin, line);
	std::stringstream ssin(line);
	while (ssin.good() && i < 4){
		ssin >> arr[i];
		++i;
	}
	value = atof(arr[0].c_str());
	if ((strcmp(arr[1].c_str(), "Celsius")) == 0)
		printPrecision(value * 9.0 / 5.0 + 32.0, "Fahrenheit");
	else if ((strcmp(arr[1].c_str(), "Fahrenheit")) == 0)
		printPrecision(5.0 / 9.0 * (value - 32.0), "Celsius");
	else
		return (84);
	return (0);
}
