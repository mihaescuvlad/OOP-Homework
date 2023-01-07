#ifndef SHAPE_H
#define SHAPE_H

class IShape
{
public:
	virtual void draw() = 0;
	virtual double getArea() = 0;
};

std::unique_ptr<IShape> MakeCircle(const double& radius);
std::unique_ptr<IShape> MakeSquare(const double& side);
std::unique_ptr<IShape> MakeTriangle(const double& side1, const double& side2, const double& side3);

#endif
