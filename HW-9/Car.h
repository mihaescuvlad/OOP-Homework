#ifndef CAR_H
#define CAR_H
#include <string>
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	std::string m_name;
public:
	Car(const std::string& name);
	void start();
};

#endif
