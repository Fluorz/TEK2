/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
**        plazzaInterface.cpp
*/

#include <string>
#include "plazzaInterface.hpp"

PlazzaInterface::PlazzaInterface(int n) :
	_maxThreadsPerSlave(n)
{
}

PlazzaInterface::~PlazzaInterface()
{
}

int PlazzaInterface::getMaxThreadsPerSlave()
{
	return (this->_maxThreadsPerSlave);
}

std::string PlazzaInterface::getCommandBuffer()
{
	return (this->_commandBuffer);
}

void PlazzaInterface::setCommandBuffer(std::string ss)
{
	this->_commandBuffer = ss;
}

void PlazzaInterface::setTaskNumber(int n)
{
	this->_taskNb = n;
}