/*
** EPITECH PROJECT, 2018
** cpp_d14m
** File description:
**        Cocunut.cpp
*/

#include "Coconut.hpp"

Coconut::Coconut()
	: Fruit("coconut", 15)
{
}

Coconut::~Coconut()
{
}

std::string Coconut::getName() const
{
	return (_name);
}

int Coconut::getVitamins() const
{
	return (_vitamins);
}
