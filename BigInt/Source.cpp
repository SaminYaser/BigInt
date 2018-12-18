#include <iostream>
#include "BigInt.h"

using namespace std;

int main()
{
	BigInt a("0"), b("1"), c;

	/*if (a == b)	std::cout << "1" << std::endl;
	else cout << "0" << endl;*/

	

	c = a - 10;
	c.PRINT();

	int pagla;
	std::cin >> pagla;
	return 0;
}