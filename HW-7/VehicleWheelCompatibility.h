#ifndef VEHICLE_WHEEL_COMPATIBILITY_H
#define VEHICLE_WHEEL_COMPATIBILITY_H

enum class VehicleType
{
	carriage,
	street_car,
	offroad_car,
	race_car,
	truck,
	other
};

enum class WheelType
{
	wooden,
	wooden_luxury,
	bike,
	motorcycle,
	street_small,
	street_medium,
	street_big,
	offroad_small,
	offroad_medium,
	offroad_big,
	dirt_rally,
	snow_rally,
	tarmac_rally,
	semi_slick,
	slick,
	truck,
	tractor,
	invalid_wheel_type
};

bool validateWheelForCar(const WheelType& wheel, const VehicleType& vehicle);

#endif

