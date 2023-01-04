#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double side1, double side2) : m_side1{side1}, m_side2{side2}
{
	std::cout << "Constructor Rectangle\n";
}

Rectangle::~Rectangle()
{
	std::cout << "Deconstructor Rectangle\n";
}

double Rectangle::getArea()
{
	return m_side1 * m_side2;
}