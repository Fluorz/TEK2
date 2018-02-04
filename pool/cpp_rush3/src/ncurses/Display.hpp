//
// EPITECH PROJECT, 2018
// Display
// File description:
//
//

#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include <curses.h>
#include <ncurses.h>
#include <vector>
#include "MonitorCore.hpp"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Display
{
public:
	Display();
	virtual ~Display();
public:
	bool		displayAll();
	void            displayRam() const;
	void            displayName() const;
	void            displaySystem() const;
	void            displayNetwork() const;
	void            displayDate() const;
	void            displayBattery() const;
	void            displayCPU() const;
	void		displayDisk() const;
	void		displayTemp() const;
	void		displayPartition() const;
	void 		printSquare(int x, int y, int width, int height, int color) const;
	void        	printProgressBar(int x, int y, int size, int percent) const;
	void        	printBattery(int x, int y, int size, int percent) const;
};


#endif /* _DISPLAY_HPP_ */
