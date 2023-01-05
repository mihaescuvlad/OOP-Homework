#include "Driver.h"

Driver::Driver(){}

Driver::Driver(Car& car) : m_car{ std::make_unique<Car>(car) }
{
} 

void Driver::setCar(Car& car)
{
	m_car = std::make_unique<Car>(car);
}

void Driver::reset()
{
	m_car.reset(nullptr);
}