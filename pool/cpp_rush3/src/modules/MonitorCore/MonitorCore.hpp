/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        MonitorModule.hpp
*/

#ifndef MONITORMODULE_HPP_
#define MONITORMODULE_HPP_

#include "CPUModule.hpp"
#include "Ram.hpp"
#include "User.hpp"
#include "Network.hpp"
#include "Battery.hpp"
#include "Disk.hpp"
#include "Temperature.hpp"
#include "Partitions.hpp"

class MonitorCore
{
public:
	MonitorCore();
	~MonitorCore();
public:
	static MonitorCore getInstance();

	Ram *getRam() const;
	CPUModule *getCPU() const;
	Network *getNetwork() const;
	User *getUser() const;
	Battery *getBattery() const;
	Disk *getDisk() const;
	Temperature *getTemperature() const;
	Partitions *getPartitions() const;

private:
	Ram *_ramModule;
	CPUModule *_cpuModule;
	Network *_networkModule;
	User *_userModule;
	Battery *_batteryModule;
	Disk *_diskModule;
	Temperature *_temperatureModule;
	Partitions *_partitions;
};

void	to_test();

#endif
