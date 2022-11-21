#include "Student.h"

Student::Student(std::string name, short age, double grade) : m_name{ name }, m_age{ age }, m_grade{ grade }
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

Student::operator std::string() const noexcept {
	// No std::format support, yet!
	char str[150];

	sprintf(str, "Student( %s, Y: %hi, Z: %f)", this->m_name.c_str(), this->m_age, this->m_grade);

	return std::string(str);
}