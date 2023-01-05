#include "VehicleWheelCompatibility.h"
#include <unordered_map>

bool validateWheelForCar(const WheelType& wheel, const VehicleType& vehicle)
{
	std::unordered_map<VehicleType, std::list<WheelType>> compatibilityMap{
		{VehicleType::carriage, {WheelType::wooden, WheelType::wooden_luxury}},
		{VehicleType::street_car, {WheelType::street_small, WheelType::street_medium, WheelType::offroad_small, WheelType::semi_slick}},
		{VehicleType::offroad_car, {WheelType::street_medium, WheelType::street_big, WheelType::offroad_medium, WheelType::offroad_big}},
		{VehicleType::race_car, {WheelType::street_medium, WheelType::offroad_medium, WheelType::dirt_rally, WheelType::snow_rally, WheelType::tarmac_rally, WheelType::semi_slick, WheelType::slick}},
		{VehicleType::truck, {WheelType::truck}},
		{VehicleType::other, {WheelType::invalid_wheel_type}}
	};

	std::list<WheelType> compatibleWheels{ compatibilityMap.at(vehicle) };
	for (const auto& compatibleWheel : compatibleWheels)
		if (compatibleWheel == wheel)
			return true;

	return false;
}