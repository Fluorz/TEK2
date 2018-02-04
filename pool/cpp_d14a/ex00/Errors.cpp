/*
** EPITECH PROJECT, 2018
** cpp_d14a
** File description:
**        Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message,
	std::string const &component)
	: _message(message), _component(component)
{
}

NasaError::~NasaError()
{
}

const char *NasaError::what() const noexcept
{
	return (_message.data());
}
std::string const &NasaError::getComponent() const
{
	return (_component);
}

std::string const &NasaError::getMessage() const
{
	return (_message);
}

MissionCriticalError::MissionCriticalError(std::string const &message,
	std::string const &component)
	: NasaError(message, component)
{
}

MissionCriticalError::~MissionCriticalError()
{
}

std::string const &MissionCriticalError::getComponent() const
{
	return (_component);
}

std::string const &MissionCriticalError::getMessage() const
{
	return (_message);
}

LifeCriticalError::LifeCriticalError(std::string const &message,
	std::string const &component)
	: NasaError(message, component)
{
}

LifeCriticalError::~LifeCriticalError()
{
}

std::string const &LifeCriticalError::getComponent() const
{
	return (_component);
}

std::string const &LifeCriticalError::getMessage() const
{
	return (_message);
}

UserError::UserError(std::string const &message,
	std::string const &component)
	: NasaError(message, component)
{
}

UserError::~UserError()
{
}

std::string const &UserError::getComponent() const
{
	return (_component);
}

std::string const &UserError::getMessage() const
{
	return (_message);
}

CommunicationError::CommunicationError(std::string const &message)
	: NasaError(message, "CommunicationDevice")
{
}

CommunicationError::~CommunicationError()
{
}

std::string const &CommunicationError::getComponent() const
{
	return (_component);
}

std::string const &CommunicationError::getMessage() const
{
	return (_message);
}
