#include "Circle.h"
#include <iostream>
#include <numbers>

Circle::Circle(const double& radius) : m_radius(radius)
{
}

void Circle::draw()
{
	std::cout << "Circle o\n";
}

double Circle::getArea()
{
	return std::numbers::pi_v<double> * pow(m_radius, 2.0);
}