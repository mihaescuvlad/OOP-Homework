#include "Car.h"
#include <iostream>

Car::Car(const std::string& name) : m_name{ name }
{
}

void Car::start()
{
	std::cout << "Starting " << m_name << " car.\n";
}