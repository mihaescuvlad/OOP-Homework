#include <iostream>
#include "Form.h"
#include "Rectangle.h"

int main()
{
    std::cout << "Starting program (main scope)\n";
    Form form1;
    {
        std::cout << "New local scope\n";
        Form form2;
        Rectangle rectangle1{ 2.0, 2.0 };
        std::cout << "The rectangle's area is: " << rectangle1.getArea() << '\n';
        std::cout << "Exit scope\n";
    }
    Rectangle rectangle1;

    std::cout << "Leaving main scope\n";

    /*
     * 1) start a bus engine 
	 * 2) how many commuters are in a bus/busstation? 
     * 3) what are the buses stopping in some busstation
     * 4) what are the stations a bus will stop in
     * 5) move an apartment from a person to a student
  	 * 6) add a student to a busStation, bus and car 
  	 * 7) move a mosquito from an apartment to a bus or to a car 
  	 * 8) is a specific mosquito in a specificbus, car or apartment? 
  	 * 9) find a student based on some address and check if he's in a the bus driveby some specific driver
     */

    /*
     * class Car {
     * private:
     *    Person* m_driver;
     *    std::vector<Person*> m_passangers;
     * public:
     *    void start();
     *    void addPassanger(Person* person);
     *    Person* getDriver() const;
     * };
     *
     * class Bus : public Car {
     * private:
     *    uint16_t m_noCommunters;
     *    std::vector<BusStation*> m_stops;
     * public:
     *    uint16_t getNoCommuters() const;
     *    std::vector<BusStation*> getStops() const;
     *    void addPassanger(Person* person);
     * };
     *
     * class BusStation {
     * private:
     *     std::vector<Bus*> m_stoppingBuses;
     *     std::vector<Person*> m_waitingPersons;
     * public:
     *    std::vector<Bus*> getStoppingBuses() const;
     *    void addWaitingPerson(Person* person);
     * };
     *
     * class Person {
     * private:
     *    std::string m_name;
     *    std::string m_address;
     * public:
     *    std::string getName() const;
     *    std::string getAddress() const;
     * };
     *
     * class Student : public Person {
     * 
     * };
     *
     * class Apartment {
     * private:
     *    auto m_owner;
     * public:
     *    auto changeOwner(const auto& newOwner);
     * };
     *
     * class Mosquito {     // 8) Yes.
     * private:
     *    auto m_currentLocation;
     * public:
     *    auto changeOLocation(const auto& newLocation);
     * };
     *
     * bool checkDriverOfStudentAtAddress(const vector<Student*>& students, const vector<Bus*>& buses, const std::string& studentAddress, const std::string& driverName) {
     *    for(const auto& student : students) {
     *       if(student.getAddress() == studentAddress) {
     *          for(const auto& bus : buses) {
     *             if(bus.getDriver() == driverName) {
     *                return true;
     *             }
     *          }
     *       }
     *    }
     *
     *    return false;
     * }
     */


    return 0;
}
