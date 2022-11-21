#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include "Rectangle.h"
#include "Student.h"
#include "ComplexNumber.h"

void printHighestGradedStudents(const std::vector<Student*>& studentVector)
{
    try
    {
        if (studentVector.size() == 0.0)
            throw "No students to search for in function \"printHighestGradedStudents\", parameter \"const std::vector<Student>& studentVector\"\n";
    }
    catch (const char* exception)
    {
        std::cerr << "\nError: " << exception << '\n';

        // We can choose to terminate the program or return to the scope where the function was called. I chose to return out of the function.
        //exit(EXIT_FAILURE);
        return;
    }

    std::cout << "Listing the students with the best grade: \n";

    double maxGrade = (*std::max_element(studentVector.begin(), studentVector.end(), [](const Student* a, const Student* b)
        {
            return a->getGrade() < b->getGrade();
        }))->getGrade();

        std::ranges::for_each(studentVector, [maxGrade](const Student* student)
            {
                if (student->getGrade() == maxGrade)
                    std::cout << static_cast<std::string>(*student) << '\n';
            });
}

int main()
{
    Rectangle rectangle{ {0.0, 2.5},{3.0, 6.0} };
    std::cout << "The area of a rectangle with the extreme points located at (0.0, 2.5) and (3.0, 6.0) has the perimeter: "
        << rectangle.getPerimeter() << " and the area: " << rectangle.getArea() << '\n';

    std::vector<Student*> studentVector{ new Student({"Vlad", 19, 9.0}), new Student({"Madalin", 20, 7.5}), new Student({"Costel", 21, 10.0}), new Student({"Daria", 20, 10.0}) };

    std::cout << "The contents of the studentVector before ordering: \n";
    for (const auto& student : studentVector) std::cout << static_cast<std::string>(*student) << '\n';
    std::cout << '\n';

    std::ranges::sort(studentVector, [](const Student* a, const Student* b)
        {
            return a->getName() < b->getName();
        });

    std::cout << "The contents of the studentVector ordered by name: \n";
    for (const auto& student : studentVector) std::cout << static_cast<std::string>(*student) << '\n';
    std::cout << '\n';

    std::ranges::sort(studentVector, [](const Student* a, const Student* b)
        {
            return a->getAge() < b->getAge();
        });

    std::cout << "The contents of the studentVector ordered by age: \n";
    for (const auto& student : studentVector) std::cout << static_cast<std::string>(*student) << '\n';
    std::cout << '\n';

    std::ranges::sort(studentVector, [](const Student* a, const Student* b)
        {
            return a->getGrade() < b->getGrade();
        });

    std::cout << "The contents of the studentVector ordered by grade: \n";
    for (const auto& student : studentVector) std::cout << static_cast<std::string>(*student) << '\n';
    std::cout << '\n';

    std::string searchByName = "Madalin";
    std::vector<Student*>::iterator studentIterator = std::ranges::find_if(studentVector, [searchByName](const Student* current)
        {
            return current->getName() == searchByName;
        });

    std::cout << "Searching for a student named \"" << searchByName << "\": " << static_cast<std::string>(*(*studentIterator)) << '\n';

    short searchByAge = 19;
    studentIterator = std::ranges::find_if(studentVector, [searchByAge](const Student* current)
        {
            return current->getAge() == searchByAge;
        });

    std::cout << "Searching for a student of age \"" << searchByAge << "\": " << static_cast<std::string>(*(*studentIterator)) << '\n';

    double searchByGrade = 10.0;
    studentIterator = std::ranges::find_if(studentVector, [searchByGrade](const Student* current)
        {
            return current->getGrade() == searchByGrade;
        });

    std::cout << "Searching for a student of age \"" << searchByGrade << "\": " << static_cast<std::string>(*(*studentIterator)) << '\n';

    printHighestGradedStudents(studentVector);

    // This is so bad, I'm never using pointers in this way again...
    std::cout << "The number of \"Student\" instances is: " << studentVector[0]->getInstances() << '\n';
    studentVector.push_back(new Student({ "Gigel", 24, 4.5 }));
    std::cout << "The number of \"Student\" instances after creating Gigel: " << studentVector[0]->getInstances() << '\n';

    // Breaks the DRY principle
    delete studentVector.back();
    studentVector.pop_back();

    delete studentVector.back();
    studentVector.pop_back();

    std::cout << "The number of \"Student\" instances after destroying 2 objects: " << studentVector[0]->getInstances() << '\n';

    // Really prone to memory leaks, I was also too lazy to set the pointers to 'nullptr', i guess that next time I will use smart pointers and move semantics if possible...
    for (const auto& student : studentVector)
        delete student;

    studentVector.clear();

    printHighestGradedStudents(studentVector);

    Student* student = new Student({ "Vlad", 19, 9.0 });
    std::cout << "The number of \"Student\" instances after destroying all objects and creating a new one: " << student->getInstances() << '\n';

    delete student;

    ComplexNumber a{ 1.0, 3.0 }, b{ 2.0, 2.0 }, complexSum = a.getSum(b), complexProduct = a.getProduct(b);

    std::cout << "The sum of the ComplexNumbers 1+i*3 and 2+i*2 is: " << complexSum.getReal() << "+i*" << complexSum.getImaginary() << '\n';
    std::cout << "The product of the ComplexNumbers 1+i*3 and 2+i*2 is: " << complexProduct.getReal() << "+i*" << complexProduct.getImaginary() << '\n';

    return 0;
}