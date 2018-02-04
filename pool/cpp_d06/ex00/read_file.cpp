/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
**        read_file.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

int	print_files(char *str)
{
	std::string line;
	std::ifstream myfile (str);

	if (myfile.is_open()) {
		while (getline (myfile,line)) {
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else std::cout << "my_cat: <" << str << ">: No such file or directory" << '\n';
	return (0);
}

int main (int ac, char **av)
{
	if (ac == 1)
		std::cout << "my_cat : Usage: ./my_cat file [...]" << '\n' ;
	int	i = 1;
	while (av[i]) {
		print_files(av[i]);
		i++;
	}
  	return (0);
}
