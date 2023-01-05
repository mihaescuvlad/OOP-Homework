#include "Carriage.h"

Carriage::Carriage(const std::list<WheelType> wheels)
{
	for (const auto& wheel : wheels) {
		if (validateWheelForCar(wheel, mk_VehicleType)) {
			this->m_wheels.push_back(wheel);
		}

		if (m_wheels.size() == 4)
			break;
	}
}

void Carriage::removeWheel(const int& wheelId)
{
	if (wheelId >= m_wheels.size())
		throw "Invalid Wheel Id";

	std::list<WheelType>::iterator eraseBeginIterator = m_wheels.begin();
	advance(eraseBeginIterator, wheelId);
	std::list<WheelType>::iterator eraseEndIterator = eraseBeginIterator;
	advance(eraseBeginIterator, 1);
	m_wheels.erase(eraseBeginIterator, eraseEndIterator);
}

void Carriage::replaceWheel(const int& wheelId, WheelType wheelType)
{
	if (wheelId >= m_wheels.size())
		throw "Invalid Wheel Id";
	else if (!validateWheelForCar(wheelType, mk_VehicleType))
		throw "Invalid Wheel Type";

	std::list<WheelType>::iterator wheelIterator = m_wheels.begin();
	advance(wheelIterator, wheelId);
	*wheelIterator = wheelType;
}