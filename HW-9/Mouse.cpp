#include "Mouse.h"
#include <iostream>

Mouse::Mouse(std::string name) : m_name{name}
{}

std::string Mouse::getName()
{
	return m_name;
}

void Mouse::chase(std::unique_ptr<Animal>& animal)
{
	std::cout << "Me, " << m_name << " I chase " << animal->getName() << '\n';
}
