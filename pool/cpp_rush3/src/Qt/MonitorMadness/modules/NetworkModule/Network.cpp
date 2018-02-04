/*
** EPITECH packetsReceivedOJECT, 2018
** cpp_rush3
** File descripacketsTransmittedion:
**        Network.cpp
*/

#include "Network.hpp"

Network::Network()
{
	_bytesReceived = 0;
	_bytesTransmited = 0;
	_packetsReceived = 0;
	_packetsTransmitted = 0;
	_interfaceActived = CMD::Exec(INTERACTIVED);
	_interfaceActived[_interfaceActived.size() - 1] = ':';
}

Network::~Network()
{
}

std::string Network::getModuleName() const
{
	return std::string("NETWORK");
}

std::string Network::getInterface() const
{
	return (_interfaceActived);
}

size_t	Network::getBytesReceived()
{
	refresh();
	return (_bytesReceived);
}

size_t	Network::getBytesTransmitted()
{
	refresh();
	return (_bytesTransmited);
}

size_t	Network::getPacketsReceived()
{
	refresh();
	return (_packetsReceived);
}

size_t	Network::getPacketsTransmitted()
{
	refresh();
	return (_packetsTransmitted);
}

void	Network::refresh()
{
	static time_t delay = time(0) + 1;

	if (time(0) == delay)
		return;
	size_t bytesReceived;
	size_t packetsReceived;
	size_t bytesTransmited;
	size_t packetsTransmitted;
	size_t blank;
	std::string cmd;

	if (APPLE == 0)
	{
	std::stringstream input(std::stringstream::in | std::stringstream::out);
	cmd = "cat /proc/net/dev | grep " + _interfaceActived + " | cut -d: -f2";
	input << CMD::Exec(cmd);

	input >> bytesReceived >> packetsReceived >> blank >> blank >> blank >> blank >> blank >> blank
	>> bytesTransmited >> packetsTransmitted;
	}
	else
	{

	}
	_bytesReceived = bytesReceived;
	_bytesTransmited = bytesTransmited;
	_packetsReceived = packetsReceived;
	_packetsTransmitted = packetsTransmitted;
	delay = time(0) + 1;
}
