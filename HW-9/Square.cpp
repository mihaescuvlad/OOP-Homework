#include "Square.h"
#include <iostream>

Square::Square(const double& side) : m_side{ side }
{}

void Square::draw()
{
	std::cout << "Square |_|\n";
}

double Square::getArea()
{
	return pow(m_side, 2);
}