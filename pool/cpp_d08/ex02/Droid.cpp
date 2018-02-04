/*
** EPITECH PROJECT, 2018
** cpp_d08
** File description:
**        Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(const std::string id)
	: _id(id), _energy(50), _attack(25), _toughness(15),
	 _status(new std::string ("Standing by"))
{
	std::cout << "Droid '" << _id << "' Activated\n";
	this->BattleData = new DroidMemory();
}

Droid::Droid(const Droid &droid)
	: _id(droid._id), _energy(50), _attack(25),
	_toughness(15), BattleData(droid.BattleData)
{
	if (!droid._status) {
		_status = (new std::string ("Standing by"));
	}
	else {
		delete _status;
		_status = droid._status;
	}
	std::cout << "Droid '" << _id << "' Activated, Memory Dumped\n";
}

bool Droid::operator()(const std::string *task, size_t exp)
{
	std::string *tmp = new std::string(*task);
	size_t new_exp;

	if (this->_energy - 10 > 0) {
		this->_energy -= 10;
		if (this->getDroid()->getExp() >= exp) {
			new_exp = exp / 2;
		this->BattleData->setExp(this->BattleData->getExp()
		 + new_exp);
		 *tmp += " - Completed!";
		this->_status = new std::string(*tmp);
		return (true);
		}
		else {
		*tmp += " - Failed!";
		this->_status = new std::string(*tmp);
		this->BattleData->setExp(this->BattleData->getExp() + exp);
		return (false);
		}
	}
	this->_energy = 0;
	this->_status = new std::string("Battery Low");
	return (false);
}

Droid& Droid::operator=(const Droid &droid)
{
	if (this == &droid)
		return (*this);
	_id = droid._id;
	return (*this);
}

bool Droid::operator==(const Droid &droid) const
{
	return *_status == *(droid._status);
}

bool Droid::operator!=(const Droid &droid) const
{
	return !(*this == droid);
}

Droid& Droid::operator<<(size_t &energy)
{
	size_t min = 0;
	size_t max = 100;
	size_t need = 0;

	if (this->_energy > max || this->_energy < min || energy < min) {
		return (*this);
	}
	else {
		need = max - this->_energy;
		if (need > energy) {
			need = energy;
			energy = 0;
			this->_energy += need;
		}
		else {
			this->_energy += need;
			energy -= need;
		}
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &s, const Droid &droid)
{
	return (s << "Droid '" << droid.getId() << "', "
	<< (*droid.getStatus()) << ", "
	<< droid.getEnergy());
}

Droid::~Droid()
{
	std::cout << "Droid '" << _id << "' Destroyed\n";
}

std::string Droid::getId() const
{
	return _id;
}

size_t Droid::getEnergy() const {
	return _energy;
}

size_t Droid::getAttack() const {
	return _attack;
}

size_t Droid::getToughness() const
{
	return _toughness;
}

std::string *Droid::getStatus() const
{
	return (_status);
}

void Droid::setId(std::string id)
{
	this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
	this->_energy = energy;
}

void Droid::setStatus(std::string* status)
{
	if (this->_status) {
		delete this->_status;
	}
	this->_status = status;
}

DroidMemory *Droid::getDroid() const
{
	return (this->BattleData);
}

void	Droid::setDroid(DroidMemory *droid)
{
	this->BattleData = droid;
}
