#ifndef CAT_H
#define CAT_H
#include <iostream>

#include "Animal.h"

class Cat : public Animal {
private:
	std::string m_name;
public:
	Cat(std::string name);

	std::string getName() override;

	void chase(std::unique_ptr<Animal>& animal) override;
};

#endif