/*
** EPITECH PROJECT, 2018
** cpp_d14a
** File description:
**        Errors.hpp
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
public:
	NasaError(std::string const &message,
		std::string const &component = "Unknown");
	virtual ~NasaError();
	const char *what() const noexcept override;
	virtual std::string const &getComponent() const;
	virtual std::string const &getMessage() const;
protected:
	std::string _message;
	std::string _component;
};

class MissionCriticalError : public NasaError
{
public:
	MissionCriticalError(std::string const &message,
		std::string const &component = "Unknown");
	virtual ~MissionCriticalError();
	std::string const &getComponent() const;
	std::string const &getMessage() const;
};

class LifeCriticalError : public NasaError
{
public:
	LifeCriticalError(std::string const &message,
		std::string const &component = "Unknown");
	virtual ~LifeCriticalError();
	std::string const &getComponent() const;
	std::string const &getMessage() const;
};

class UserError : public NasaError
{
public:
	UserError(std::string const &message,
		std::string const &component = "Unknown");
	virtual ~UserError();
	std::string const &getComponent() const;
	std::string const &getMessage() const;
};

class CommunicationError : public NasaError
{
public:
	CommunicationError(std::string const &message);
	virtual ~CommunicationError();
	std::string const &getComponent() const;
	std::string const &getMessage() const;
};

#endif
