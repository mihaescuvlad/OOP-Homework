#ifndef CAR_H
#define CAR_H

#include "Person.h"

class Car
{
private:
	// I was too lazy to create a Driver class
	using Driver = Person;

	uint16_t m_age;
	Driver m_driver;
public:
	Car(uint16_t age, Driver driver);

	void setDriver(const Driver& driver);
	Driver getDriver();
	void swapDriver(Car& car);
};

#endif