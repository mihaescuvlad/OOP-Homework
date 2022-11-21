#ifndef STUDENT_H
#define STUDENT_H
#include <string>

#include "Person.h"

class Student : public Person
{
private:
	double m_grade;
public:
	Student(std::string name, uint16_t age, double grade);

	double getGrade() const;

	friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

#endif

