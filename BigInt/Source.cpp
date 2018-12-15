#include <iostream>
#include "BigInt.h"

using namespace std;

int main()
{
	int ca = 1;
	double ba = -1;

	BigInt a(0), b(1), c, d;

	/*if (a == b)	std::cout << "1" << std::endl;
	else cout << "0" << endl;*/

	

	c = a + b;
	c.PRINT();

	int pagla;
	std::cin >> pagla;
	return 0;
}