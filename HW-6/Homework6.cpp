#include <iostream>
#include "ComplexNumber.h"

int main()
{
    // T 6.1
    ComplexNumber complex1{1.0, 5.0}, complex2{2.5, 10.0};

    std::cout << "The first complex number is: ";
    complex1.printNum();
    std::cout << "The second complex number is: ";
    complex2.printNum();
    std::cout << '\n';

    // T 6.2
    std::cout << "The sum of the two complex numbers is: ";
    complex1 = complex1 + complex2;
    complex1.printNum();
    std::cout << '\n';

    std::cout << "The modulus of the first complex number is: " << ~complex1 << '\n';
    std::cout << "The modulus of the second complex number is: " << ~complex2 << '\n';
    std::cout << '\n';

    // T 6.3
    std::cout << "Comparing the two complex numbers by their modulus." << '\n';
    (complex1 < complex2) ? std::cout << "The first number has a smaller modulus.\n" : std::cout << "The second number has a smaller modulus.\n";
    std::cout << '\n';

    // T 6.1 - Raising to an integer power
    std::cout << "Another complex number: ";
    ComplexNumber complex3{ 1.0, 1.0 };
    complex3.printNum();
    std::cout << '\n';

    std::cout << "Raising the complex number to the power of 5: ";
    complex3 = complex3^5;
    complex3.printNum();
}
