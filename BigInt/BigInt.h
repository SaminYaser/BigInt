#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>


class BigInt
{
private:
	std::vector<int> number;
	bool sign = 0;

public:
	//Constructor
	BigInt();
	BigInt(int);
	BigInt(long long);
	BigInt(std::string);
	BigInt(float);
	BigInt(double);
	BigInt(long double);
	~BigInt();

	//Utility Functions
	bool getSign();
	std::string getNumber();
	void negate();
	void PRINT();

	//Allocation


	//Addition
	BigInt add(BigInt b);
	BigInt add(int);
	BigInt add(long long);
	BigInt add(std::string);
	BigInt add(float);
	BigInt add(double);
	BigInt add(long double);

	//Substraction
	BigInt sub(BigInt b);

	//Comparisons
	bool operator == (BigInt);
	bool operator != (BigInt);
	bool operator < (BigInt);
	bool operator <= (BigInt);
	bool operator > (BigInt);
	bool operator >= (BigInt);
};

