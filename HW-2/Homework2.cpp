#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>
#include <ranges> // C++20 or above

// T 2.1
void swapElements(int& a, int& b)   // This function uses XOR-Swap to prevent the usage of extra memory
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

// T 2.2
int roundFloat(const float& n, const bool& isRoundedTo100 = false)
{
	switch(isRoundedTo100)
	{
	case true:
    {
        int newNum = static_cast<int>(n);
        return (newNum % 100 < 50) ? newNum - (newNum % 100) : newNum + 100 - (newNum % 100);
    }
	default:
        return static_cast<int>(round(n));
	}
}

// T 2.3
// Defining the Student struct and the helper functions
struct Student
{
    std::string name;
    uint16_t age;
	float grade;

    // Overloaded the << operator to make printing the answer easier (not required by the problem statement)
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend bool operator>=(const Student& c1, const Student& c2);
};

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << "Student(" << student.name << ", " << student.age << ", " << student.grade << ')';
    return out;
}

// The overload on operator>= helps with assignment 2.8
bool operator>=(const Student& student1, const Student& student2)
{
    return student1.grade > student2.grade;
}

// Required max function
Student getMaxGradeStudent(const std::list<Student>& studentList)
{
    Student bestStudent{};
	for(const auto& student : studentList)
	{
        if (bestStudent.grade < student.grade)
            bestStudent = student;
	}

    return bestStudent;
}

// T 2.4
std::string timeToString(long milisecs = time(0))   // No need to overload when we can use a default variable (overload is commented below)
{
	time_t currentTime = milisecs;  // implicit conversion to time_t
    char buffer[255];

    strftime(buffer, sizeof buffer, "%Y-%m-%d %H:%M:%S", localtime(&currentTime)); // localtime is unsafe, so we add the preprocessor definition "_CRT_SECURE_NO_WARNINGS"

    std::string timeString = buffer;

    return timeString;
}

// Below is the overload for timeToString
/*
std::string timeToString()
{
	time_t currentTime = time(0);
    char buffer[255];

    strftime(buffer, sizeof buffer, "%Y-%m-%d %H:%M:%S", localtime(&currentTime)); // localtime is unsafe, so we add the preprocessor definition "_CRT_SECURE_NO_WARNINGS"

    std::string timeString = buffer;

    return timeString;
}
*/

// T 2.5
int getSize(int x)
{
    return sizeof(x);
}

int getSize(double x)
{
    return sizeof(x);
}

int getSize(char* x)
{
    return static_cast<int>(strlen(x)); // The return type is of size_t so we cast it to int
}

// T 2.7
struct ComplexNumber
{
    double real, imaginary;
};

double modulus(const ComplexNumber& num)
{
    return sqrt(pow(num.real, 2) + pow(num.imaginary, 2));
}

double modulus(const double& real, const double& imaginary)
{
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}

// T 2.8
template<typename T>
T getMaxOfThree(T firstItem, T secondItem, T thirdItem) {
    if (firstItem >= secondItem && firstItem >= thirdItem)
        return firstItem;
    else if (secondItem >= firstItem && secondItem >= thirdItem)
        return secondItem;
    else
        return thirdItem;
}

template<> // Overload the template for char*
char* getMaxOfThree<char*>(char* firstItem, char* secondItem, char* thirdItem) {
    std::string newFirstItem = firstItem, newSecondItem = secondItem, newThirdItem = thirdItem;

    if (newFirstItem >= newSecondItem && newFirstItem >= newThirdItem)
        return firstItem;
    else if (newSecondItem >= newFirstItem && newSecondItem >= newThirdItem)
        return secondItem;
    else
        return thirdItem;
}

// T 2.9
template<typename T>
T computeSum(T first, T second)
{
    return first + second;
}

// T 2.10
template<typename T>
void interchangeData(T& first, T& second)
{
    T temp{first};
    first = second;
    second = temp;
}

/*
 * Arrays cannot be modified, and they merely decay to temporary pointers, they are not really pointers and cannot be swapped.
 * Therefore we will use some tricks to swap the arrays.
 * This template will not work if the arrays are of a different size.
 */
template<size_t maxSize>
void interchangeData(char(&first)[maxSize], char(&second)[maxSize]) {
    for (size_t iter = 0; iter != maxSize; ++iter)
        std::swap(first[iter], second[iter]);
}

// T 2.11
double computeOperation(const double& num1, const double& num2, const char& operation)
{
	switch(operation)
	{
	case '+':
        return num1 + num2;
	case '-':
        return num1 - num2;
	default:
        std::cerr << "Error: Invalid operation";
        return std::numeric_limits<double>::min();
	}
}

// T 2.12
struct Person
{
    std::string name;
    uint16_t age;

    friend std::ostream& operator<<(std::ostream& out, const Person& person);
};

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << "Person(" << person.name << ", " << person.age << ')';
    return out;
}

struct Cat
{
    std::string name;
    uint16_t age;
    Person* owner = nullptr;
};

struct Car
{
    std::string producer, licenseNumber;
    uint16_t age;
};

// This returns the object that has the minimum age, it was not required by the exercise
/*
template<typename A, typename B>
auto getMinAgeObject(A first, B second)
{
    return (first.age < second.age) ? first : second;
}
*/

template<typename A, typename B>
double getMinAge(A first, B second)
{
    return std::min(first.age, second.age);
}

template<typename A, typename B>
bool isSameAge(A first, B second)
{
    return first.age == second.age;
}

// T 2.14
double solveFirstDegreeEquation(const double& a, const double& b)   // ax + b = 0
{
    try
    {
        if (a == 0.0)
            throw "Division by 0 in function \"solveFirstDegreeEquation\"\n";

        return -b / a;
    }
    catch (const char* exception)
    {
        std::cerr << "\nError: " << exception << '\n';
        //abort();  // A more aggressive way of terminating the program
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // T 2.1
    int firstElement = 3, secondElement = 5;
    std::cout << "Swapping element \"a = " << firstElement << "\" with element \"b = " << secondElement << "\" using the \"swapElements()\" function:\n";
    swapElements(firstElement, secondElement);
    std::cout << "The elements are: \"a = " << firstElement << "\", \"b = " << secondElement << "\"\n";

    std::cout << '\n';
    // T 2.2
    const float roundThis = 53.2f;
    std::cout << "Rounding element \"a = " << roundThis << "\" using the \"roundFloat()\" function: " << roundFloat(roundThis) << '\n';
    std::cout << "Rounding element \"a = " << roundThis << "\" to the nearest 100 using the \"roundFloat()\" function: " << roundFloat(roundThis, true) << '\n';

    std::cout << '\n';
    // T 2.3
    std::list<Student> students{ {"Ionut", 20, 6.1f}, {"Cristian", 21, 8.6f}, {"Madalin", 21, 9.3f }, {"Daniel", 21, 7.9f} };
    std::cout << "Getting the best student from the student list using the \"getMaxGradeStudent()\" function: " << getMaxGradeStudent(students) << '\n';

    std::cout << '\n';
    // T 2.4
    const long givenTime = 1668338140;
    std::cout << "Getting the date from the \"givenTime\" variable using the \"timeToString()\" function: " << timeToString(givenTime) << '\n';
    std::cout << "Getting the current date using the \"timeToString()\" function: " << timeToString() << '\n';

    std::cout << '\n';
    // T 2.5
    int overloadInt = 4;
    double overloadDouble = 100.56;
    char overloadCStr[] = "Lorem ipsum dolor sit amet";     // length of 26

    std::cout << "Getting the size of the \"overloadInt\" variable using the \"getSize()\" function: " << getSize(overloadInt) << '\n';
    std::cout << "Getting the size of the \"overloadDouble\" variable using the \"getSize()\" function: " << getSize(overloadDouble) << '\n';
    std::cout << "Getting the size of the \"overloadCStr\" variable using the \"getSize()\" function: " << getSize(overloadCStr) << '\n';

    std::cout << '\n';
    // T 2.7 (Skipped 2.6 since it's optional)
    ComplexNumber complexNumber{ 4.3,7.0 };
    double complexReal = 4.3, complexImaginary = 7.0;

    std::cout << "Getting the modulus of the \"complexNumber\" variable using the \"modulus()\" function: " << modulus(complexNumber) << '\n';
    std::cout << "Getting the modulus of the \"complexReal\" and \"complexImaginary\" variables using the \"modulus()\" function: " << modulus(complexReal, complexImaginary) << '\n';

    std::cout << '\n';
    // T 2.8
    int firstIntItem = 5, secondIntItem = 10, thirdIntItem = 8;
    float firstFloatItem = 3.0f, secondFloatItem = 6.5f, thirdFloatItem = -2.9f;
    char firstCStringItem[] = "aaa", secondCStringItem[] = "xyz", thirdCStringItem[] = "abc";
    Student firstStudentItem = { "Ionut", 20, 6.1f }, secondStudentItem = { "Cristian", 21, 8.6f }, thirdStudentItem = { "Daniel", 21, 7.9f };

    std::cout << "Getting the maximum item between the \"firstIntItem\", \"secondIntItem\", \"thirdIntItem\" variables using the \"getMaxOfThree()\" function: " << getMaxOfThree(firstIntItem, secondIntItem, thirdIntItem) << '\n';
	std::cout << "Getting the maximum item between the \"firstFloatItem\", \"secondFloatItem\", \"thirdFloatItem\" variables using the \"getMaxOfThree()\" function: " << getMaxOfThree(firstFloatItem, secondFloatItem, thirdFloatItem) << '\n';
	std::cout << "Getting the maximum item between the \"firstCStringItem\", \"secondCStringItem\", \"thirdCStringItem\" variables using the \"getMaxOfThree()\" function: " << getMaxOfThree(firstCStringItem, secondCStringItem, thirdCStringItem) << '\n';
	std::cout << "Getting the maximum item between the \"firstStudentItem\", \"secondStudentItem\", \"thirdStudentItem\" variables using the \"getMaxOfThree()\" function: " << getMaxOfThree(firstStudentItem, secondStudentItem, thirdStudentItem) << '\n';

    std::cout << '\n';
    // T 2.9
    int sumFirst = 3, sumSecond = 10;
    std::cout << "Getting the sum of \"sumFirst\" and \"sumSecond\" variables using the \"computeSum()\" function: " << computeSum(sumFirst, sumSecond) << '\n';
    std::cout << "The \"computeSum()\" function will not work as expected for char, STL Contrainers, C-Style Arrays and custom data types such as structs or classes (without an overload)\n";

    std::cout << '\n';
    // T 2.10
    int firstIntSwap = 5, secondIntSwap = 10;
    float firstFloatSwap = 3.0f, secondFloatSwap = 6.5f;
    char firstCStringSwap[] = "aaa", secondCStringSwap[] = "xyz";
    Student firstStudentSwap = { "Ionut", 20, 6.1f }, secondStudentSwap = { "Cristian", 21, 8.6f };

    interchangeData(firstIntSwap, secondIntSwap);
    interchangeData(firstFloatSwap, secondFloatSwap);
    interchangeData(firstCStringSwap, secondCStringSwap);
    interchangeData(firstStudentSwap, secondStudentSwap);

    std::cout << "Getting the variables \"firstIntSwap\" and \"secondIntSwap\" after using the \"interchangeData()\" function: firstIntSwap = " << firstIntSwap << "\t secondIntSwap = " << secondIntSwap << '\n';
	std::cout << "Getting the variables \"firstFloatSwap\" and \"secondFloatSwap\" after using the \"interchangeData()\" function: firstIntSwap = " << firstFloatSwap << "\t secondIntSwap = " << secondFloatSwap << '\n';
	std::cout << "Getting the variables \"firstCStringSwap\" and \"secondCStringSwap\" after using the \"interchangeData()\" function: firstIntSwap = " << firstCStringSwap << "\t secondIntSwap = " << secondCStringSwap << '\n';
	std::cout << "Getting the variables \"firstStudentSwap\" and \"secondStudentSwap\" after using the \"interchangeData()\" function: firstIntSwap = " << firstStudentSwap << "\t secondIntSwap = " << secondStudentSwap << '\n';

    std::cout << '\n';
    // T 2.11
    double firstNum = 15.3, secondNum = 22.5;
    char operation = '+';
    // Assume we read the numbers and operation
    double(*p_computeOperation)(const double&, const double&, const char&);
    p_computeOperation = &computeOperation;

    std::cout << "The result of the operation \"" << firstNum << ' ' << operation << ' ' << secondNum << "\" computed using the \"p_computeOperation()\" function pointer is: " << p_computeOperation(firstNum, secondNum, operation) << '\n';
    
    std::cout << '\n';
    // T 2.12
    Person person{"Jon Arbuckle", 27};
    Cat cat{ "Garfield", 7, &person };
    Car car{ "1967 Mazda Cosmo", "027 Jon", 7};

    std::cout << "Getting the minimum age between the \"person\" and \"cat\" using the \"getMinAge()\" function: " << getMinAge(person, cat) << '\n';

    // We turned on boolalpha so we can print the "true" and "false" strings with ease
    std::cout << std::boolalpha;
    std::cout << "Checking to see if \"person\" and \"cat\" have the same age using the \"isSameAge()\" function: " << isSameAge(person, cat) << '\n';
    std::cout << "Checking to see if \"cat\" and \"car\" have the same age using the \"isSameAge()\" function: " << isSameAge(cat, car) << '\n';
    std::cout << std::noboolalpha;

    std::cout << '\n';
    // T 2.13
    std::vector<Person> persons{ {"Eduard", 22},{"Vlad", 19}, {"Preda", 20}, {"Robert", 21} };
    // This sorting method works only for C++20
    std::ranges::sort(persons, [](const Person& a, const Person& b) -> bool
    {
	    return a.age > b.age;
    });

    /*
    // This sorting method works for versions previous to C++20
    std::sort(persons.begin(), persons.end(), [](const Person& a, const Person& b) -> bool
    {
        return a.age > b.age;
    });
    */

    std::cout << "The vector of persons sorted by age in a descending ordered:\n";
    for(const auto& personObj : persons)
    {
        std::cout << personObj << '\n';
    }

    std::cout << '\n';
    // T 2.14
    double a = 2.0, b = -10.0;

    std::cout << "Finding the unknown \'x\' in the equation \"" << a << "x + " << b << " = 0\" using the \"solveFirstDegreeEquation()\" function: " << solveFirstDegreeEquation(a, b) << '\n';

    return 0;
}