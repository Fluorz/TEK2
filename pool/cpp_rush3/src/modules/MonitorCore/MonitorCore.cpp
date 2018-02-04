/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        MonitorCore.cpp
*/

#include "MonitorCore.hpp"

MonitorCore::MonitorCore()
{
	_ramModule = new Ram;
	_cpuModule = new CPUModule;
	_networkModule = new Network;
	_userModule = new User;
	_batteryModule = new Battery;
	_diskModule = new Disk;
	_temperatureModule = new Temperature;
	_partitions = new Partitions;
}

MonitorCore::~MonitorCore()
{
	delete _ramModule;
	delete _cpuModule;
	delete _networkModule;
	delete _userModule;
	delete _batteryModule;
	delete _diskModule;
	delete _temperatureModule;
	delete _partitions;
}

MonitorCore MonitorCore::getInstance()
{
	MonitorCore mc;

	return mc;
}

Ram *MonitorCore::getRam() const
{
	return _ramModule;
}

CPUModule *MonitorCore::getCPU() const
{
	return _cpuModule;
}

Network *MonitorCore::getNetwork() const
{
	return _networkModule;
}

User *MonitorCore::getUser() const
{
	return _userModule;
}

Battery *MonitorCore::getBattery() const
{
	return _batteryModule;
}

Disk	*MonitorCore::getDisk() const
{
	return _diskModule;
}

Temperature *MonitorCore::getTemperature() const
{
	return _temperatureModule;
}

Partitions *MonitorCore::getPartitions() const
{
	return _partitions;
}