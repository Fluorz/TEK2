/*
** EPITECH PROJECT, 2018
** cpp_d07m
** File description:
**        Federation.cpp
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length , int width, std::string name,
	 short maxWarp, int torpedo)
{
	this->_shield = 100;
	this->_photonTorpedo = torpedo;
	this->_home = EARTH;
	this->_location = this->_home;
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = maxWarp;
	this->_core = NULL;
	std::cout << "The ship USS " << name << " has been finished. It is ";
	std::cout << length << " m in length and " << width << " m in width. ";
	std::cout << "It can go to Warp " << maxWarp << "! ";
	std::cout << "Weapons are set: ";
	std::cout << this->_photonTorpedo << " torpedoes ready.\n";

}

Federation::Starfleet::Ship::Ship()
{
	this->_shield = 100;
	this->_photonTorpedo = 20;
	this->_home = EARTH;
	this->_location = this->_home;
	this->_length = 289;
	this->_width = 132;
	this->_name = "Entreprise";
	this->_maxWarp = 6;
	this->_core = NULL;
	std::cout << "The ship USS " << this->_name;
	std::cout << " has been finished. It is "  << this->_length;
	std::cout << " m in length and " << this->_width << " m in width. ";
	std::cout << " It can go to Warp " << this->_maxWarp << "! ";
	std::cout << "Weapons are set: ";
	std::cout << this->_photonTorpedo << " torpedoes ready.\n";
}

Federation::Starfleet::Ship::~Ship()
{
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
	std::cout << "USS " << this->_name << ": The core is set.\n";
}

void	Federation::Starfleet::Ship::checkCore()
{
	std::cout << "USS " << this->_name << ": The core is ";
	if (this->_core->checkReactor()->isStable() == true) {
		std::cout << "stable";
	}
	else {
		std::cout << "unstable";
	}
	std::cout << " at the time.\n";
}

bool	Federation::Starfleet::Ship::move(int warp, Destination d)
{
	if (warp <= this->_maxWarp && d != this->_location &&
		this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return (true);
	}
	else
		return (false);
}

bool	Federation::Starfleet::Ship::move(int warp)
{
	return (move(warp, this->_home));
}

bool	Federation::Starfleet::Ship::move(Destination d)
{
	return (move(this->_maxWarp, d));
}

bool	Federation::Starfleet::Ship::move()
{
	return (move(this->_maxWarp, this->_home));
}

int	Federation::Starfleet::Ship::getShield()
{
	return (this->_shield);
}

void	Federation::Starfleet::Ship::setShield(int shield)
{
	this->_shield = shield;
}

int	Federation::Starfleet::Ship::getTorpedo()
{
	return (this->_photonTorpedo);
}

void	Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
	this->_photonTorpedo = torpedo;
}

void	Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
	if (this->_photonTorpedo == 0) {
		std::cout << this->_name;
		std::cout << ": No more torpedo to fire, ";
		std::cout << this->_Captain->getName() << "!\n";
	}
	else {
	this->_photonTorpedo -= 1;
	std::cout << this->_name;
	std::cout << ": Firing on target. ";
	std::cout << this->_photonTorpedo << " ";
	std::cout << "torpedoes remaining.\n";
	target->setShield(target->getShield() - 50);
	}
}

void	Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
	if (this->_photonTorpedo - torpedoes < 0) {
		std::cout << this->_name;
		std::cout << ": No enough torpedoes to fire, ";
		std::cout << this->_Captain->getName() << "!\n";
	}
	else {
	this->_photonTorpedo -= torpedoes;
	std::cout << this->_name;
	std::cout << ": Firing on target. ";
	std::cout << this->_photonTorpedo << " ";
	std::cout << "torpedoes remaining.\n";
	target->setShield(target->getShield() - 50 * torpedoes);
	}
}

WarpSystem::Core	*Federation::Ship::getCore()
{
	return (this->_core);
}

Federation::Ship::Ship(int length, int width, std::string name)
{
	this->_home = VULCAN;
	this->_location = this->_home;
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = 1;
	std::cout << "The independant ship " << name ;
	std::cout << " just finished its construction. It is ";
	std::cout << length << " m in length and ";
	std::cout << width << " m in width." << '\n';
}

Federation::Ship::~Ship()
{
}

void	Federation::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
	std::cout << this->_name << ": The core is set.\n";
}

void	Federation::Ship::checkCore()
{
	std::cout << this->_name << ": The core is ";
	if (this->_core->checkReactor()->isStable() == true) {
		std::cout << "stable";
	}
	else {
		std::cout << "unstable";
	}
	std::cout << " at the time.\n";
}

bool	Federation::Ship::move(int warp, Destination d)
{
	if (warp <= this->_maxWarp && d != this->_location &&
		this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return (true);
	}
	else
		return (false);
}

bool	Federation::Ship::move(int warp)
{
	return (move(warp, this->_home));
}

bool	Federation::Ship::move(Destination d)
{
	return (move(this->_maxWarp, d));
}

bool	Federation::Ship::move()
{
	return (move(this->_maxWarp, this->_home));
}
