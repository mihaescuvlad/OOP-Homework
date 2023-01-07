#include "Drawing.h"
#include <iostream>

Drawing::Drawing(std::unique_ptr<IShape>&& shape) : m_shape(std::move(shape))
{
}

void Drawing::drawShape() const
{
	m_shape->draw();
}

void Drawing::printArea() const
{
	std::cout << "The area is: " << m_shape->getArea() << '\n';
}

double Drawing::getArea() const
{
	return m_shape->getArea();
}