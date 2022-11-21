#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
	double m_x, m_y;
public:
	Coordinate(double x = 0.0, double y = 0.0);

	double getX() const;
	double getY() const;
};

#endif