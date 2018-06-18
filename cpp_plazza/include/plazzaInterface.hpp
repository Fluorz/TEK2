/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        plazzaInterface.hpp
*/

#ifndef PLAZZA_INTERFACE_HPP
# define PLAZZA_INTERFACE_HPP

class PlazzaInterface
{
	public:
		PlazzaInterface(int);
		~PlazzaInterface();

		int getMaxThreadsPerSlave();
		
		std::string getCommandBuffer();
		void setCommandBuffer(std::string);
		
		void setTaskNumber(int);
	private:
		int _maxThreadsPerSlave;
		int _taskNb;
		std::string _commandBuffer;
};

#endif