#include "Person.h"

#include <iostream>

Person::Person(std::string name, uint16_t age) : m_name{ name }, m_age{ age }
{
}

std::string Person::getName() const
{
	return m_name;
}

short Person::getAge() const
{
	return m_age;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
	out << "Person(" << person.getName() << ", " << person.getAge() << ')';
	return out;
}