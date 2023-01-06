#include <iostream>
#include <vector>

#include "Car.h"
#include "CarPersonUtils.h"
#include "ComplexNumber.h"
#include "Person.h"

int main()
{
    // T 8.1
    ComplexNumber complex1{ 1.0, 5.0 }, complex2{ 2.5, 10.0 };

    std::cout << "The first complex number is: ";
    complex1.printNum();
    std::cout << "The second complex number is: ";
    complex2.printNum();
    std::cout << '\n';

    std::cout << "Getting the minimum complex number by modulus." << '\n';
    complex2.getMin(complex1).printNum();
    std::cout << '\n';

    // T 8.2
    double num1 = 6.1;
    std::cout << "Comparing a complex number and a double." << '\n';
    (complex1 < num1) ? std::cout << "The first number is smaller.\n" : std::cout << "The second number is bigger.\n";
    std::cout << '\n';

    int num2 = 8;
    std::cout << "Comparing a complex number and an int." << '\n';
    (complex2 < num2) ? std::cout << "The first number is smaller.\n" : std::cout << "The second number is bigger.\n";
    std::cout << '\n';

    // T 8.3
    std::vector<Person> persons{{21}, {18}, {55}, {23}, {49}};
    std::vector<Car> cars{{1}, {0}, {7}};

    CarPersonUtils<Person, Car> car_person_utils{ persons, cars };

    std::cout << "The average age between the two lists is: " << car_person_utils.getAverage() << '\n';


    return 0;
}
