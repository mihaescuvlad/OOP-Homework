#include "CarDriverManager.h"

CarDriverManager::CarDriverManager(Car& car, Driver& driver)
{
	m_car = std::move(car);
	m_driver = std::move(driver);
}

void CarDriverManager::removeDriver()
{
	m_driver.reset();
}

void CarDriverManager::removeCar()
{
	m_car.reset();
}

void swapDriver(CarDriverManager& a, CarDriverManager& b)
{
	Driver temp = std::move(a.m_driver);
	a.m_driver = std::move(b.m_driver);
	b.m_driver = std::move(temp);
}

void swapCar(CarDriverManager& a, CarDriverManager& b)
{
	Car temp = std::move(a.m_car);
	a.m_car = std::move(b.m_car);
	b.m_car = std::move(temp);
}

void createRelationship(Car& car, Driver& driver)
{
	car.setDriver(driver);
	driver.setCar(car);
}