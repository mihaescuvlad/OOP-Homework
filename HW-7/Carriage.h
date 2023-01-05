#ifndef CARRIAGE_H
#define CARRIAGE_H
#include <list>

#include "VehicleWheelCompatibility.h"

class Carriage
{
private:
	const VehicleType mk_VehicleType{ VehicleType::carriage };
	std::list<WheelType> m_wheels;
public:
	Carriage(const std::list<WheelType> wheels = { WheelType::wooden, WheelType::wooden, WheelType::wooden, WheelType::wooden });

	void removeWheel(const int& wheelId = 0);
	void replaceWheel(const int& wheelId = 0, WheelType wheelType = WheelType::wooden);
};

#endif
