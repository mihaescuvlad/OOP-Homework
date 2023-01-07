#ifndef MOUSE_H
#define MOUSE_H

#include <string>
#include "Animal.h"

class Mouse : public Animal {
private:
	std::string m_name;
public:
	Mouse(std::string name);

	std::string getName() override;

	void chase(std::unique_ptr<Animal>& animal) override;
};

#endif