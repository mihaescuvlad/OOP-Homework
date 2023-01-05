#include "Student.h"

#include <iostream>

Student::Student(const std::string& name) : m_name{ name }
{
}

void Student::printName() const
{
	std::cout << m_name;
}