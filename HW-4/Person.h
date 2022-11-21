#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
	std::string m_name;
	uint16_t m_age;
public:
	Person(std::string name, uint16_t age);

	std::string getName() const;
	short getAge() const;

	friend std::ostream& operator<<(std::ostream& out, const Person& person);
};

#endif