#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
	int m_age;
public:
	Person(const int& age = 0);

	int getAge() const;
};

#endif