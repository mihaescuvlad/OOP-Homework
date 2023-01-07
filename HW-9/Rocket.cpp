#include "Rocket.h"
#include <iostream>

Rocket::Rocket(const std::string& name) : m_name{ name }
{
}

void Rocket::start()
{
	std::cout << "Starting " << m_name << " rocket.\n";
}