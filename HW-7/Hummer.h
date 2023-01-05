#ifndef HUMMER_H
#define HUMMER_H
#include <list>
#include "VehicleWheelCompatibility.h"

class Hummer
{
private:
	const VehicleType mk_VehicleType{ VehicleType::offroad_car };
	std::list<WheelType> m_wheels;
public:
	Hummer(const std::list<WheelType> wheels = { WheelType::offroad_medium, WheelType::offroad_medium, WheelType::offroad_medium, WheelType::offroad_medium });

	void removeWheel(const int& wheelId = 0);
	void replaceWheel(const int& wheelId = 0, WheelType wheelType = WheelType::offroad_medium);
};

#endif