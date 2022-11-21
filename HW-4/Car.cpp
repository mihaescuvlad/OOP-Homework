#include "Car.h"

Car::Car(uint16_t age, Driver driver) : m_age{age}, m_driver{driver}
{
}

void Car::setDriver(const Driver& driver)
{
	m_driver = driver;
}

Car::Driver Car::getDriver()
{
	return m_driver;
}

void Car::swapDriver(Car& car)
{
	Driver temp = m_driver;
	m_driver = car.getDriver();
	car.setDriver(temp);
}
