/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
**        MonitorModule.hpp
*/

#ifndef MONITORMODULE_HPP_
#define MONITORMODULE_HPP_

#include "../CPUModule/CPUModule.hpp"
#include "../RamModule/Ram.hpp"
#include "../UserModule/User.hpp"
#include "../NetworkModule/Network.hpp"
#include "../BatteryModule/Battery.hpp"
#include "../DiskModule/Disk.hpp"
#include "../TemperatureModule/Temperature.hpp"

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
private:
	Ram *_ramModule;
	CPUModule *_cpuModule;
	Network *_networkModule;
	User *_userModule;
	Battery *_batteryModule;
	Disk *_diskModule;
	Temperature *_temperatureModule;
};

#endif
