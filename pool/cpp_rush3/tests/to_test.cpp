/*
** EPITECH PROJECT, 2018
** test_criterion
** File description:
**        unit_test.c
*/

#include <iostream>
#include "MonitorCore.hpp"

void	to_test()
{
	std::cout << "--CPU MODULE--\n";
	std::cout << "Number core : " << MonitorCore::getInstance().getCPU()->getCoreNb() << std::endl;
	std::cout << "Usage core 1 : " << MonitorCore::getInstance().getCPU()->getCore(0).getUsage() << std::endl;
	std::cout << "Freq core 1 : " << MonitorCore::getInstance().getCPU()->getCore(0).getFreq() << std::endl;
	std::cout << "Get CPU Name : " << MonitorCore::getInstance().getCPU()->getCore(0).getName() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getCPU()->getModuleName() << std::endl;

	std::cout << "\n--RAM MODULE--\n";
	std::cout << "Max Ram : " << MonitorCore::getInstance().getRam()->getMaxRam() << std::endl;
	std::cout << "Used Ram : " << MonitorCore::getInstance().getRam()->getUsedRam() << std::endl;
	std::cout << "Max Swap : " << MonitorCore::getInstance().getRam()->getMaxSwap() << std::endl;
	std::cout << "Used Swap : " << MonitorCore::getInstance().getRam()->getUsedSwap() << std::endl;
	std::cout << "Buffers : " << MonitorCore::getInstance().getRam()->getBuffers() << std::endl;
	std::cout << "Number Process : " << MonitorCore::getInstance().getRam()->getNbProcess() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getRam()->getModuleName() << std::endl;

	std::cout << "\n--USER MODULE --\n";
	std::cout << "User Name : " << MonitorCore::getInstance().getUser()->getUserName() << std::endl;
	std::cout << "Kernel : " << MonitorCore::getInstance().getUser()->getKernel() << std::endl;
	std::cout << "Os Version : " << MonitorCore::getInstance().getUser()->getOsVersion() << std::endl;
	std::cout << "Machine : " << MonitorCore::getInstance().getUser()->getMachine() << std::endl;
	std::cout << "SysName : " << MonitorCore::getInstance().getUser()->getSysName() << std::endl;
	std::cout << "Time : " << MonitorCore::getInstance().getUser()->getTime() << std::endl;
	std::cout << "Up Time : " << MonitorCore::getInstance().getUser()->getUpTime() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getUser()->getModuleName() << std::endl;

	std::cout << "\n--NETWORK MODULE --\n";
	std::cout << "Bytes Received : " << MonitorCore::getInstance().getNetwork()->getBytesReceived() << std::endl;
	std::cout << "Bytes Transmitted : " << MonitorCore::getInstance().getNetwork()->getBytesTransmitted() << std::endl;
	std::cout << "Packets Received : " << MonitorCore::getInstance().getNetwork()->getPacketsReceived() << std::endl;
	std::cout << "Packets Transmitted : " << MonitorCore::getInstance().getNetwork()->getPacketsTransmitted() << std::endl;
	std::cout << "Interface : " << MonitorCore::getInstance().getNetwork()->getInterface() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getNetwork()->getModuleName() << std::endl;

	std::cout << "\n--DISK MODULE--\n";
	std::cout << "Disk Read : " << MonitorCore::getInstance().getDisk()->getDiskRead() << std::endl;
	std::cout << "Disk write : " << MonitorCore::getInstance().getDisk()->getDiskWrite() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getDisk()->getModuleName() << std::endl;

	std::cout << "\n--BATTERY LEVEL--\n";
	std::cout << "Battery level : " << MonitorCore::getInstance().getBattery()->getBattery() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getBattery()->getModuleName() << std::endl;

	std::cout << "\n--TEMPERATURE CPU--\n";
	std::cout << "Temperature : "<< MonitorCore::getInstance().getTemperature()->getTemperature() << std::endl;
	std::cout << "Module name : " << MonitorCore::getInstance().getTemperature()->getModuleName() << std::endl;

	std::cout << "\n--Partitions --\n";
	int i = 0;
	std::cout << "Number Partitions : "<< MonitorCore::getInstance().getPartitions()->getNumber() << std::endl;

	while (i != MonitorCore::getInstance().getPartitions()->getNumber())
	{
		std::cout << '\n';
		std::cout << "Id : " << i << '\n';
		std::cout << "Partitions name : "<< MonitorCore::getInstance().getPartitions()->getPartitionsName(i) << std::endl;
		std::cout << "Partitions size : "<< MonitorCore::getInstance().getPartitions()->getSize(i) << std::endl;
		i++;
	}

	std::cout << "Module name : " << MonitorCore::getInstance().getPartitions()->getModuleName() << std::endl;
	std::cout << "\n--ERROR HANDLER--\n";
	CMD::Exec("coco");
	return;
}
