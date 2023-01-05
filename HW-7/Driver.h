#ifndef DRIVER_H
#define DRIVER_H
#include "Car.h"

class Driver
{
protected:
	std::unique_ptr<Car> m_car{nullptr};
public:
	Driver();
	Driver(Car& car);

	void setCar(Car& car);
	void reset();
};

#endif