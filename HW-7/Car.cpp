#include "Car.h"

Car::Car(){}

Car::Car(Driver& driver) : m_driver{ std::make_unique<Driver>(driver) }
{
}

void Car::setDriver(Driver& driver)
{
	m_driver = std::make_unique<Driver>(driver);
}

void Car::reset()
{
	m_driver.reset(nullptr);
}