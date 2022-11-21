#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(Coordinate leftLimit, Coordinate rightLimit) : m_leftLimit{ leftLimit }, m_rightLimit{ rightLimit }
{
	m_side1Length = abs(m_leftLimit.getX()-m_rightLimit.getX());
	m_side2Length = abs(m_leftLimit.getY() - m_rightLimit.getY());
}

double Rectangle::getPerimeter() const
{
	return 2.0 * m_side1Length + 2.0 * m_side2Length;
}

double Rectangle::getArea() const
{
	return m_side1Length * m_side2Length;
}