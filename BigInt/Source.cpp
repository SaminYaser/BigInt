#include <iostream>
#include "BigInt.h"

int main()
{
	int ca = 1;
	double ba = -1;

	BigInt a("9"), b("-01"), c;

	c = a.add(1);
	c.PRINT();

	int pagla;
	std::cin >> pagla;
	return 0;
}