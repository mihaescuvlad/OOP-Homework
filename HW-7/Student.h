#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
private:
	std::string m_name;
public:
	Student(const std::string& name = "");

	void printName() const;
};

#endif
