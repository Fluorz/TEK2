/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        Network.hpp
*/

#ifndef _NETWORK_
# define _NETWORK_

#include <iostream>
#include <sstream>
#include "../IMonitorModule.hpp"
#include "../../base/CMD/CMD.hpp"

#ifdef __APPLE__
const char INTERACTIVED[] = "route get google.com | grep interface | awk -F \": \" '{print $2}'";
const int APPLE = 1;
#else
const char INTERACTIVED[] = "cat /proc/net/wireless | tail -1 | awk -F \":\" '{print $1}'";
const int APPLE = 0;
#endif

class Network : public IMonitorModule
{
public:
	Network();
	virtual ~Network();
public:
	size_t getBytesReceived();
	size_t getBytesTransmitted();
	size_t getPacketsReceived();
	size_t getPacketsTransmitted();
	std::string getInterface() const;
	void	refresh();

	std::string getModuleName() const;
protected:
	std::string _interfaceActived;
	size_t _bytesReceived;
	size_t _bytesTransmited;
	size_t _packetsReceived;
	size_t _packetsTransmitted;
};

#endif
