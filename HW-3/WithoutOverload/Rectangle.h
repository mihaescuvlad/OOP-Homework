#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Coordinate.h"

class Rectangle
{
private:
	Coordinate m_leftLimit, m_rightLimit;
	double m_side1Length, m_side2Length;
public:
	Rectangle(Coordinate leftLimit, Coordinate rightLimit);

	double getPerimeter() const;
	double getArea() const;
};

#endif