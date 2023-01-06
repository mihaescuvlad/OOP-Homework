#ifndef CAR_PERSON_UTILS_H
#define CAR_PERSON_UTILS_H

#include <vector>
#include <numeric>
#include "Car.h"
#include "Person.h"

template<class T, class U>
class CarPersonUtils
{
private:
	std::vector<T> m_persons;
	std::vector<U> m_cars;
public:
	CarPersonUtils(const T& obj1 = {}, const U& obj2 = {}) : m_persons{ {obj1} }, m_cars{ {obj2} }
	{}

	CarPersonUtils(const std::vector<T>& objs1, const std::vector<U>& objs2) : m_persons{ objs1 }, m_cars{ objs2 }
	{}

	void addElement(const T& element)
	{
		m_persons.push_back(element);
	}

	void addElement(const U& element)
	{
		m_cars.push_back(element);
	}

	[[nodiscard]] float getAverage() const
	{
		float average = 0.0f;

		average += std::accumulate(m_persons.begin(), m_persons.end(), 0.0f, [](const T& a, const T& b)
			{
				return a.getAge() + b.getAge();
			});

		average += std::accumulate(m_cars.begin(), m_cars.end(), 0.0f, [](const U& a, const U& b)
			{
				return a.getAge() + b.getAge();
			});

		return average / (m_persons.size() + m_cars.size());
	}
};

#endif