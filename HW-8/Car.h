#ifndef CAR_H
#define CAR_H

class Car
{
private:
	int m_age;
public:
	Car(const int& age = 0);

	int getAge() const;
};

#endif