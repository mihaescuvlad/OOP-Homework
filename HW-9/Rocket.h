#ifndef ROCKET_H
#define ROCKET_H
#include <string>
#include "Vehicle.h"

class Rocket : public Vehicle
{
private:
	std::string m_name;
public:
	Rocket(const std::string& name);
	void start();
};

#endif
