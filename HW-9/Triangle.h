#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <memory>

#include "IShape.h"

class Triangle : public IShape
{
private:
	double m_side1, m_side2, m_side3;

	double getSemiPerimeter();
public:
	Triangle(const double& side1, const double& side2, const double& side3);

	void draw() override;
	double getArea() override;
};

inline std::unique_ptr<IShape> MakeTriangle(const double& side1 = 0.0, const double& side2 = 0.0, const double& side3 = 0.0)
{
	return std::make_unique<Triangle>(side1, side2, side3);
}

#endif
