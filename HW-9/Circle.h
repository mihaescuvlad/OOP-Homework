#ifndef CIRCLE_H
#define CIRCLE_H
#include <memory>

#include "IShape.h"

class Circle : public IShape
{
private:
	double m_radius;
public:
	Circle(const double& radius = 0.0);

	void draw() override;
	double getArea() override;
};

inline std::unique_ptr<IShape> MakeCircle(const double& radius = 0.0)
{
	return std::make_unique<Circle>(radius);
}

#endif
