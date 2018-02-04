//
// EPITECH PROJECT, 2018
// Display
// File description:
//
//

#include <curses.h>
#include <ncurses.h>
#include <vector>
#include "Display.hpp"
#include <unistd.h>
#include <ctime>

CPUCore core = MonitorCore::getInstance().getCPU()->getCore(0);

Display::Display()
{
	displayAll();
}

Display::~Display()
{
}

void        Display::printProgressBar(int x, int y, int size, int percent) const
{
	int xStart = x;
	int color = 10;
	while (xStart < (percent * size / 100) + x)
	{
		if (xStart >= x && xStart <= x + (40 * size / 100))
		{
			color = 13;
		}
		if (xStart >= x + (40 * size / 100) && xStart <= x + (60 * size / 100))
		{
			color = 14;
		}
		if (xStart >= x + (60 * size / 100) && xStart<= x + (100 * size / 100))
		{
			color = 11;
		}
		attron(COLOR_PAIR(color));
		mvprintw(y, xStart, " ");
		attroff(COLOR_PAIR(color));
		xStart += 1;
	}
}

void        Display::printBattery(int x, int y, int size, int percent) const
{
	int xStart = x;
	int color = 10;
	while (xStart < (percent * size / 100) + x)
	{
		if (xStart >= x && xStart <= x + (20 * size / 100))
		{
			color = 11;
		}
		if (xStart >= x + (20 * size / 100) && xStart <= x + (40 * size / 100))
		{
			color = 14;
		}
		if (xStart >= x + (40 * size / 100) && xStart<= x + (100 * size / 100))
		{
			color = 13;
		}
		attron(COLOR_PAIR(color));
		mvprintw(y, xStart, " ");
		attroff(COLOR_PAIR(color));
		xStart += 1;
	}
}

void        Display::printSquare(int x, int y, int width, int height, int color) const
{
	int xStart = x;
	int yStart = y;

	while (yStart <= height + y)
	{
		xStart = x;
		while (xStart <= width + x)
		{
			if (yStart == y || yStart == y + height)
			{
				attron(COLOR_PAIR(color));
				mvprintw(xStart, yStart, " ");
				attroff(COLOR_PAIR(color));
			}
			if (xStart == x || xStart == x + width)
			{
				attron(COLOR_PAIR(color));
				mvprintw(xStart, yStart, " ");
				attroff(COLOR_PAIR(color));
			}
			xStart += 1;
		}
		yStart += 1;
	}
}

void		Display::displayName() const {
	attron(COLOR_PAIR(5));
	mvprintw(3, 3,"Computer Name :");
	attron(COLOR_PAIR(4));
	mvprintw(4, 5, MonitorCore::getInstance().getUser()->getSysName().c_str());
	attron(COLOR_PAIR(5));
	mvprintw(6, 3, "Username :");
	attron(COLOR_PAIR(4));
	mvprintw(7, 5, MonitorCore::getInstance().getUser()->getUserName().c_str());
	printSquare(1, 1, 8, 35, 12);
}

void		Display::displaySystem() const {
	std::string kernel = MonitorCore::getInstance().getUser()->getKernel();
	std::string os = MonitorCore::getInstance().getUser()->getOsVersion();
	std::string cut = os.substr(0, 16);
	attron(COLOR_PAIR(5));
	mvprintw(13, 3, "OS Name :");
	attron(COLOR_PAIR(4));
	mvprintw(14, 5, cut.c_str());
	attron(COLOR_PAIR(5));
	mvprintw(16, 3, "Kernel Version :");
	attron(COLOR_PAIR(4));
	mvprintw(17, 5, kernel.c_str());
	printSquare(11, 1, 8, 35, 12);

}

void		Display::displayRam() const {
	double total = MonitorCore::getInstance().getRam()->getMaxRam();
	double free = MonitorCore::getInstance().getRam()->getMaxRam() - MonitorCore::getInstance().getRam()->getUsedRam();
	double percent = (free / total) * 100.0;
	attron(COLOR_PAIR(5));
	mvprintw(23, 3,
		"Ram :");
	attron(COLOR_PAIR(3));
	mvprintw(24, 5,
		"Used :");
	mvprintw(25, 5,
		"Max  :");
	attron(COLOR_PAIR(4));
	mvprintw(24, 13, "%u", MonitorCore::getInstance().getRam()->getUsedRam() / 1000000);
	attron(COLOR_PAIR(3));
	mvprintw(24, 25, "Mo");
	attron(COLOR_PAIR(4));
	mvprintw(25, 13, "%u", MonitorCore::getInstance().getRam()->getMaxRam() / 1000000);
	attron(COLOR_PAIR(3));
	mvprintw(25, 25, "Mo");
	printProgressBar(5, 27, 20, 100 - percent);
	printSquare(21, 1, 8, 35, 12);

}

void		Display::displayNetwork() const {
	attron(COLOR_PAIR(5));
	mvprintw(33, 3, "Sended packages :");
	attron(COLOR_PAIR(4));
	mvprintw(34, 5, "%u", MonitorCore::getInstance().getNetwork()->getBytesReceived());
	attron(COLOR_PAIR(5));
	mvprintw(36, 3, "Received packages :");
	attron(COLOR_PAIR(4));
	mvprintw(37, 5, "%u", MonitorCore::getInstance().getNetwork()->getBytesReceived());
	attron(COLOR_PAIR(5));
	mvprintw(36, 25, "Interface: ");
	attron(COLOR_PAIR(4));
	mvprintw(37, 25, MonitorCore::getInstance().getNetwork()->getInterface().c_str());
	printSquare(31, 1, 8, 35, 12);

}

void		Display::displayBattery() const {
	attron(COLOR_PAIR(5));
	mvprintw(33, 41, "Battery Percentage :");
	attron(COLOR_PAIR(4));
	mvprintw(34, 43, "%u", MonitorCore::getInstance().getBattery()->getBattery());
	printBattery(45, 39, 20, MonitorCore::getInstance().getBattery()->getBattery());
	printSquare(31, 39, 10, 35, 12);

}

float getCore0()
{
	static float lastUser, lastNice, lastSys, lastIdle = 0;
	float user, nice, sys, idle, totalUsgTime, usg, totalTimeOverall = 0;
	std::string cpu;
	std::string cmd = std::string(CPU_USAGE) + (char) (0 + 48);
	std::stringstream ss;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle;
	totalUsgTime = (user - lastUser) + (nice - lastNice) + (sys - lastSys);
	totalTimeOverall = totalUsgTime + (idle - lastIdle);
	usg = (100.0 * totalUsgTime) / totalTimeOverall;
	lastUser = user;
	lastNice = nice;
	lastSys = sys;
	lastIdle = idle;
	return usg;
}

float getCore1()
{
	static float lastUser, lastNice, lastSys, lastIdle = 0;
	float user, nice, sys, idle, totalUsgTime, usg, totalTimeOverall = 0;
	std::string cpu;
	std::string cmd = std::string(CPU_USAGE) + (char) (1 + 48);
	std::stringstream ss;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle;
	totalUsgTime = (user - lastUser) + (nice - lastNice) + (sys - lastSys);
	totalTimeOverall = totalUsgTime + (idle - lastIdle);
	usg = (100.0 * totalUsgTime) / totalTimeOverall;
	lastUser = user;
	lastNice = nice;
	lastSys = sys;
	lastIdle = idle;
	return usg;
}

float getCore2()
{
	static float lastUser, lastNice, lastSys, lastIdle = 0;
	float user, nice, sys, idle, totalUsgTime, usg, totalTimeOverall = 0;
	std::string cpu;
	std::string cmd = std::string(CPU_USAGE) + (char) (2 + 48);
	std::stringstream ss;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle;
	totalUsgTime = (user - lastUser) + (nice - lastNice) + (sys - lastSys);
	totalTimeOverall = totalUsgTime + (idle - lastIdle);
	usg = (100.0 * totalUsgTime) / totalTimeOverall;
	lastUser = user;
	lastNice = nice;
	lastSys = sys;
	lastIdle = idle;
	return usg;
}

float getCore3()
{
	static float lastUser, lastNice, lastSys, lastIdle = 0;
	float user, nice, sys, idle, totalUsgTime, usg, totalTimeOverall = 0;
	std::string cpu;
	std::string cmd = std::string(CPU_USAGE) + (char) (3 + 48);
	std::stringstream ss;

	ss << CMD::Exec(cmd);
	ss >> cpu >> user >> nice >> sys >> idle;
	totalUsgTime = (user - lastUser) + (nice - lastNice) + (sys - lastSys);
	totalTimeOverall = totalUsgTime + (idle - lastIdle);
	usg = (100.0 * totalUsgTime) / totalTimeOverall;
	lastUser = user;
	lastNice = nice;
	lastSys = sys;
	lastIdle = idle;
	return usg;
}

void		Display::displayCPU() const {
	attron(COLOR_PAIR(5));
	mvprintw(3, 78, "CPU Name :");
	attron(COLOR_PAIR(4));
	mvprintw(4, 80, MonitorCore::getInstance().getCPU()->getCore(0).getName().c_str());
	attron(COLOR_PAIR(5));
	mvprintw(6, 78, "CPU Freq :");
	attron(COLOR_PAIR(4));
	mvprintw(7, 80, "%f",MonitorCore::getInstance().getCPU()->getCore(0).getFreq());
	attron(COLOR_PAIR(5));
	mvprintw(9, 78,"CPU Core Number :");
	attron(COLOR_PAIR(4));
	mvprintw(10, 81, "%u", MonitorCore::getInstance().getCPU()->getCoreNb());
	printSquare(1, 76, 11, 45, 12);
	attron(COLOR_PAIR(5));
	mvprintw(14, 78, "CPU Core Usage :");
	usleep(40000);
	printProgressBar(78, 20, 20, getCore0());
	printProgressBar(78, 22, 20, getCore1());
	printProgressBar(78, 24, 20, getCore2());
	printProgressBar(78, 26, 20, getCore3());
}


void		Display::displayTemp() const
{
	attron(COLOR_PAIR(5));
	mvprintw(13, 41, "Temperature :");
	attron(COLOR_PAIR(4));
	mvprintw(14, 43, "%u", MonitorCore::getInstance().getTemperature()->getTemperature() / 1000);
	printSquare(12, 38, 5, 35, 12);
}


void		Display::displayDisk() const
{
	attron(COLOR_PAIR(5));
	mvprintw(33, 78, "Disk Read :");
	attron(COLOR_PAIR(4));
	mvprintw(34, 80, "%u", MonitorCore::getInstance().getDisk()->getDiskRead());
	attron(COLOR_PAIR(5));
	mvprintw(36, 78, "Disk Write :");
	attron(COLOR_PAIR(4));
	mvprintw(37, 80, "%u", MonitorCore::getInstance().getDisk()->getDiskWrite());
	double total = MonitorCore::getInstance().getRam()->getMaxSwap();
	double free = MonitorCore::getInstance().getRam()->getUsedSwap();
	double percent = (free / total) * 100.0;
	printProgressBar(39, 76, 20, 100 - percent);
	printSquare(31, 76, 10, 35, 12);

}

void		Display::displayPartition() const
{
	int	i = 0;
	attron(COLOR_PAIR(5));
	mvprintw(100, 100, "Number Partition :");
	attron(COLOR_PAIR(4));
	mvprintw(100, 100, "%d", MonitorCore::getInstance().getPartitions()->getNumber());
	while (i != MonitorCore::getInstance().getPartitions()->getNumber()) {
		attron(COLOR_PAIR(5));
		mvprintw(100, 100, "Partition Name :");
		attron(COLOR_PAIR(4));
		mvprintw(100, 100, MonitorCore::getInstance().getPartitions()->getPartitionsName(i).c_str());
		attron(COLOR_PAIR(5));
		mvprintw(100, 100, "Partition Size:");
		attron(COLOR_PAIR(4));
		mvprintw(100, 100, "%d", MonitorCore::getInstance().getPartitions()->getSize(i));
	}
	printSquare(100, 100, 9, 17, 12);
}

unsigned int        *upTimeToString(time_t seconds)
{
    unsigned int    *inttoprint;
    inttoprint = new unsigned int[4];
    seconds = static_cast<unsigned int>(seconds);
    inttoprint[0] = seconds / 86400;
    seconds = seconds % 86400;
    inttoprint[1] = seconds / 3600;
    seconds = seconds % 3600;
    inttoprint[2] = seconds / 60;
    seconds = seconds % 60;
    inttoprint[3] = seconds;
    return inttoprint;
}

void        Display::displayDate() const
{
    attron(COLOR_PAIR(5));
    mvprintw(23, 41, "UpTime :");
    attron(COLOR_PAIR(4));
    time_t  time = MonitorCore::getInstance().getUser()->getUpTime();
    unsigned int    *uptime = upTimeToString(time);
    mvprintw(24, 43, "D %d, H %d, M %d, S %d", uptime[0], uptime[1], uptime[2], uptime[3]);
    attron(COLOR_PAIR(5));
    mvprintw(26, 41, "Time :");
    attron(COLOR_PAIR(4));
    time = MonitorCore::getInstance().getUser()->getTime();
    mvprintw(27, 43, "%s", ctime(&time));
    printSquare(21, 39, 8, 35, 12);
    delete uptime;
}

bool		Display::displayAll()
{
	int key;
	initscr();
	curs_set(FALSE);
	noecho();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLACK, COLOR_GREEN);
	init_pair(14, COLOR_BLACK, COLOR_YELLOW);
	init_pair(15, COLOR_BLACK, COLOR_CYAN);
	init_pair(16, COLOR_BLACK, COLOR_MAGENTA);
	keypad(stdscr, TRUE);
	timeout(1);
	displayName();
	displaySystem();
	displayBattery();
	while (1) {
		displayRam();
		displayNetwork();
		displayDate();
		displayDisk();
		displayCPU();
		displayTemp();
		refresh();
		key = getch();
		if (key == ' ') {
			system("reset");
			endwin();
			return true;
		}
		refresh();
		usleep(5000);
		key = 0;
	}
	return false;
}
