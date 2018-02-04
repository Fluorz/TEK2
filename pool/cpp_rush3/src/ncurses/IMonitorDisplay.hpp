//
// EPITECH PROJECT, 2018
// IMonitorDisplay
// File description:
// 
//

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <vector>
#include "IMonitorModule.hpp"

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay();
	virtual bool displayAll() = 0;
};


#endif