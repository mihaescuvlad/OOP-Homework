#include "Group.h"

#include <iostream>

Group::Group(const std::string& name, const std::list<Student> students) : m_name{name}, m_students{students}
{
}

void Group::addStudent(const Student& student)
{
	m_students.push_back(student);
}

void Group::displayData() const
{
	std::cout << "Students in group " << m_name << ":\n";
	for (const auto& student : m_students) {
		student.printName();

		if(&student != &m_students.back())
			std::cout << ", ";
	}
	std::cout << '\n';
}