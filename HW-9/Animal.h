#ifndef ANIMAL_H
#define ANIMAL_H
#include <memory>
#include <string>

class Animal
{
public:
	virtual std::string getName() = 0;
	virtual void chase(std::unique_ptr<Animal>& animal) = 0;
};

#endif