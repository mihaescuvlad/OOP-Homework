#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "Drawing.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Vehicle.h"
#include "Car.h"
#include "Rocket.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Mouse.h"

int main()
{
    // T 9.1, T 9.3
    Drawing triangle{MakeTriangle(3, 5.5, 2.6)};
    triangle.drawShape();
    triangle.printArea();

    Drawing circle{ MakeCircle(2.5) };
    circle.drawShape();
    circle.printArea();

    Drawing square{ MakeSquare(2.0) };
    square.drawShape();
    square.printArea();

    // T 9.4
    std::vector<Drawing> drawings;
    drawings.push_back(std::move(triangle));
    drawings.push_back(std::move(circle));
    drawings.push_back(std::move(square));

    double areaSum = std::accumulate(drawings.begin(), drawings.end(), 0.0, [](const double& a, const Drawing& b)
        {
	        return a + b.getArea();
	    });
    std::cout << "The area of all of the drawings is: " << areaSum << '\n';

    // T 9.2
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("Toyota Celica 1998"));
    vehicles.push_back(std::make_unique<Rocket>("NASA Artemis 1"));
    std::ranges::for_each(vehicles, [](const auto& item)
    {
            item->start();
    });

    // T 9.5
    std::vector<std::unique_ptr<Animal>> animalsChasingList;
    animalsChasingList.push_back(std::make_unique<Dog>("Hotdog"));
    animalsChasingList.push_back(std::make_unique<Dog>("Rusty"));
    animalsChasingList.push_back(std::make_unique<Cat>("Old Tom"));
	animalsChasingList.push_back(std::make_unique<Mouse>("Jerry"));
    animalsChasingList.push_back(std::make_unique<Cat>("Tom"));

    for (size_t animalIndex = 0; animalIndex < animalsChasingList.size() - 1; ++animalIndex)
        animalsChasingList.at(animalIndex)->chase(animalsChasingList.at(animalIndex + 1));

    return 0;
}