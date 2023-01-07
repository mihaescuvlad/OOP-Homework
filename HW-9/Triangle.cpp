#include "Triangle.h"
#include <iostream>

Triangle::Triangle(const double& side1, const double& side2, const double& side3) : m_side1{side1}, m_side2{side2}, m_side3{side3}
{}

double Triangle::getSemiPerimeter()
{
	return (m_side1 + m_side2 + m_side3) / 2.0;
}

void Triangle::draw()
{
	std::cout << "Triangle /_\\\n";
}

double Triangle::getArea()
{
	double s = getSemiPerimeter();
	return sqrt(s * (s - m_side1) * (s - m_side2) * (s - m_side3));
}