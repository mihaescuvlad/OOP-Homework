#ifndef CAR_H
#define CAR_H
#include <memory>

#include "Driver.h"

class Car
{
protected:
	std::unique_ptr<Driver> m_driver;
public:
	Car();
	Car(Driver& driver);

	void setDriver(Driver& driver);
	void reset();
};

#endif