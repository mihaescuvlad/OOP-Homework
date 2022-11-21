#include <iostream>

#include "Car.h"
#include "FriendGroup.h"
#include "Student.h"
#include "StudentList.h"

int main()
{
    FriendGroup friendGroup{"Gasca Fericita", {new Person({"Matei", 16}), new Person({"Daniel", 15}), new Person({"Cristian", 16})}};

    std::cout << "The friends in the group are: \n" << friendGroup << '\n';

	std::cout << "Adding \"Vlad\" to the group...\n";

    friendGroup.addPerson(new Person({ "Vlad", 19 }));
    std::cout << "The friends in the group are: \n" << friendGroup << '\n';

    std::cout << "Today is Vlad's birthday, let's update his age!\n";
    friendGroup.updatePerson("Vlad", new Person({ "Vlad", 20 }));
    std::cout << "The friends in the group are: \n" << friendGroup << '\n';

    std::cout << "It was actually a lie, it's not Vlad's birthday today. He is leaving the friend group.\n";
    friendGroup.removePerson("Vlad");
    std::cout << "The friends in the group are: \n" << friendGroup << '\n';


    StudentList studentList{ std::list<Student*>{new Student({"Matei", 16, 7.35}), new Student({"Daniel", 15, 5.0}), new Student({"Cristian", 16, 9.5}), new Student({"Vlad", 19, 9.0})} };
    std::cout << "The student with the highest grade is: " << studentList.getMaxGradeStudent()->getName() << '\n';

    Student* firstFiveGradedStudent = studentList.getFirstFiveGradeStudent();
    if (firstFiveGradedStudent)
        std::cout << "The student with the grade equal to \'5.0\' is: " << firstFiveGradedStudent->getName();
    firstFiveGradedStudent = nullptr;
    delete firstFiveGradedStudent;

    Car car1( 36, {"Costel Fagaras", 20} ), car2{25, {"Dani Cristinescu", 23}};
    std::cout << "The driver of the first car is " << car1.getDriver().getName() << " and the driver of the second car is " << car2.getDriver().getName() << '\n';

    std::cout << "Swapping the drivers of the cars...\n";
    car1.swapDriver(car2);
    std::cout << "After the swap the driver of the first car is " << car1.getDriver().getName() << " and the driver of the second car is " << car2.getDriver().getName() << '\n';

    /*
     * T 4.5 - Investigate the use of pseudo-constructors with members as pointers
     * Anything that involves the use of raw pointers increases the risk of memory leaks by forgetting to free the memory as well as the
     * appearance of "dangling pointers" when the pointers are not set to 'nullptr' and could be later accessed (accessing unallocated memory).
     * The use of pseudo-constructors (constructors with member initializer-lists) that have pointer members is relatively harmless if the proper safety precautions
     * are taken into consideration. Overall raw pointers should be avoided and smart pointers should be used. Move semantics might be preferred when constructing
     * classes that have a pseudo-constructor with member pointers.
     *
     * T 5.5 - A car is stopped by the Police for routine check. Common documents are required. Based on some actions, organize classes and data.
     * Class "Documents" will become become a part of class "Person" (composition).
     * The documents class will be composed of 3 other classes:
     *   - IdentificationDocument
     *   - DriverLicense
     *   - CarRegistration
     * It could be argued that some documents should be kept inside of the car, but the law requires the person to have possession of those documents
     * during the routine check, therefore they will be placed inside of the "Person" class.
     * Each class will have an owner pointer which will point to the "Person" object as well as an emission and expiration date.
     * The "IdentificationDocument" class will have data such as the birth date, full legal name, an unique identification number, etc.
     * The "DriverLicense" will have a list of a custom data type (enum class PermitCategories) which will have all of the categories of vehicles (from the ones listed in the
     * enumerator) that the driver has.
     * The "CarRegistration" will have a pointer to the "Car" object
     *
     * A getter will be provided for the Documents class as well as a printing function (if necessary)
     *
     * T 4.7 - Define class structure with attributes, methods and access identifiers (public, private, protected) for and application managing
     * Bus, BusStation, Address, Driver, Commuter, Mosquito, Engine, Car
     *
     * Car -> Base class for Bus                        | private, public inheritance
     * Engine -> Composition with Car (is part of Car)  | private
     * Driver -> Composition with Car                   | private
     * Commuter -> Composition with Bus                 | private
     * Address -> Base class for BusStation             | private, public inheritance
     * Mosquito -> Composition with Car, Address        | private (and inexistent if it's cold outside)
     */

    return 0;
}
