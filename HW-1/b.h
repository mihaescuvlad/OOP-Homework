#ifndef B_H
#define B_H
#include "a.h"

void boo()
{
	std::cout << "Function \"boo()\" from the \"b.h\" header has been called, calling function \"test()\"..." << std::endl;

	test();
}

#endif