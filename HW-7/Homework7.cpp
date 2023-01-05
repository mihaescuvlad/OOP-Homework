#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

#include "CarDriverManager.h"
#include "Group.h"
#include "Hummer.h"

int main()
{
    // T 7.1
    Hummer hummer;
    hummer.removeWheel(2);
    hummer.replaceWheel(1, WheelType::offroad_big);

    // T 7.2
    std::list<Group> groups{ {"A", {{"Ionut"}, {"Robert"}, {"Costel"}}}, {"B", {{"Robert"}, {"Preda"}, {"Gabi"}}} };

    std::ranges::for_each(groups, [](const Group& group) {group.displayData(); });

    // T 7.3
    // Having 2 objects pointing to one another is only possible with std::shared_ptr and it's considered a bad practice
    // I only implemented some snippets of code that would not run to show that the relation between the 2 objects is not good.

    /*
    Car car1, car2, car3;
    Driver driver1, driver2, driver3;

    createRelationship(car1, driver1);
    createRelationship(car2, driver2);
    createRelationship(car3, driver3);

    std::vector<CarDriverManager> car_driver_managers{{car1, driver1}, {car2, driver2}, {car3, driver3}};

    std::cout << "The CarDriverManager list has " << car_driver_managers.size() << " elements.\n";

    car_driver_managers[0].removeCar();
    car_driver_managers[0].removeDriver();
    std::cout << "The driver and the car in the first position of the list have been removed.\n";

    swapCar(car_driver_managers[1], car_driver_managers[2]);
    std::cout << "The car of the second and third elements in the list have been swapped.\n";

    swapDriver(car_driver_managers[1], car_driver_managers[2]);
    std::cout << "The driver of the second and third elements in the list have been swapped.\n";
    */

    return 0;
}
