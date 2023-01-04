#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Form.h"

class Rectangle : public Form
{
private:
	double m_side1, m_side2;
public:
	Rectangle(double side1 = 0.0, double side2 = 0.0);
	~Rectangle();

	double getArea();
};

#endif