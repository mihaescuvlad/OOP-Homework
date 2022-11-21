#include "StudentList.h"

#include <algorithm>
#include <iostream>

StudentList::StudentList(std::list<Student*> studentList) : m_studentList{studentList}
{
}

StudentList::~StudentList()
{
	for (const auto& student : m_studentList)
		delete student;
}

Student* StudentList::getMaxGradeStudent() const
{
    return *std::max_element(m_studentList.begin(), m_studentList.end(), [](const Student* a, const Student* b)
        {
            return a->getGrade() < b->getGrade();
        });
}

Student* StudentList::getFirstFiveGradeStudent() const
{
	for(Student* student : m_studentList)
		if (student->getGrade() == 5.0)
			return student;

	std::cerr << "Warning: No student with a grade equal to \'5.0\' found. Returning \'nullptr\'.";
	return nullptr;
}