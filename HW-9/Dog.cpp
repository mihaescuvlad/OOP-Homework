#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : m_name{ name }
{}

std::string Dog::getName()
{
	return m_name;
}

void Dog::chase(std::unique_ptr<Animal>& animal)
{
	std::cout << "Me, " << m_name << " I chase " << animal->getName() << '\n';
}