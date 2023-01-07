#ifndef DRAWING_H
#define DRAWING_H
#include <memory>

#include "IShape.h"

class Drawing
{
private:
	std::unique_ptr<IShape> m_shape;
public:
	Drawing(std::unique_ptr<IShape>&& shape);
	
	void drawShape() const;
	void printArea() const;

	double getArea() const;
};

#endif
