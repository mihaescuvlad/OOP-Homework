#ifndef DOG_H
#define DOG_H
#include <iostream>

#include "Animal.h"

class Dog : public Animal {
private:
	std::string m_name;
public:
	Dog(std::string name);

	std::string getName() override;

	void chase(std::unique_ptr<Animal>& animal) override;
};

#endif