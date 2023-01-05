#ifndef CAR_DRIVER_MANAGER_H
#define CAR_DRIVER_MANAGER_H

#include "Car.h"
#include "Driver.h"

class CarDriverManager
{
private:
	Car m_car;
	Driver m_driver;
public:
	CarDriverManager(Car& car, Driver& driver);

	void removeDriver();
	void removeCar();
	friend void swapDriver(CarDriverManager& a, CarDriverManager& b);
	friend void swapCar(CarDriverManager& a, CarDriverManager& b);
};

void createRelationship(Car& car, Driver& driver);

#endif