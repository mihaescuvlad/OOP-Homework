#ifndef SQUARE_H
#define SQUARE_H
#include <memory>

#include "IShape.h"

class Square : public IShape
{
private:
	double m_side;
public:
	Square(const double& side = 0.0);

	void draw() override;
	double getArea() override;
};

inline std::unique_ptr<IShape> MakeSquare(const double& side = 0.0)
{
	return std::make_unique<Square>(side);
}


#endif