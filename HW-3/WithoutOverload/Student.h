#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
private:
	static inline int s_instances{ 0 };

	std::string m_name;
	short m_age;
	double m_grade;
public:
	Student(std::string name, short age, double grade);
	~Student();

	std::string getName() const;
	short getAge() const;
	double getGrade() const;
	double getInstances() const;

	explicit operator std::string() const noexcept;
};

#endif
