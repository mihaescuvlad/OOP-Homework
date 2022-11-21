#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include <list>
#include "Student.h"

class StudentList
{
private:
	std::list<Student*> m_studentList;
public:
	StudentList(std::list<Student*> studentList);
	~StudentList();

	Student* getMaxGradeStudent() const;
	Student* getFirstFiveGradeStudent() const;
};

#endif