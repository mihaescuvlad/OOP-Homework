#ifndef GROUP_H
#define GROUP_H
#include "Student.h"
#include <list>
#include <string>

class Group
{
private:
	std::string m_name;
	std::list<Student> m_students;
public:
	Group(const std::string& name = "", const std::list<Student> students = {});

	void addStudent(const Student& student);
	void displayData() const;
};

#endif
