#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name) : m_name{ name }
{}

std::string Cat::getName()
{
	return m_name;
}

void Cat::chase(std::unique_ptr<Animal>& animal)
{
	std::cout << "Me, " << m_name << " I chase " << animal->getName() << '\n';
}