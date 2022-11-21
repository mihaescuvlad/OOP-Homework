#include "Student.h"

#include <iostream>

Student::Student(std::string name, short age, double grade) : m_name{name}, m_age{age}, m_grade{grade}
{
	++s_instances;
}

Student::~Student()
{
	--s_instances;
}

std::string Student::getName() const
{
	return m_name;
}

short Student::getAge() const
{
	return m_age;
}

double Student::getGrade() const
{
	return m_grade;
}

double Student::getInstances() const
{
	return s_instances;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << "Student(" << student.getName() << ", " << student.getAge() << ", " << student.getGrade() << ')';
	return out;
}
