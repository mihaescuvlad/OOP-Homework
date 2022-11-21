#include "Student.h"

#include <iostream>

Student::Student(std::string name, uint16_t age, double grade) : Person{name, age}, m_grade{ grade }
{
}

double Student::getGrade() const
{
	return m_grade;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << "Student(" << student.getName() << ", " << student.getAge() << ", " << student.getGrade() << ')';
	return out;
}