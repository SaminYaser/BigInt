#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class BigInt
{
private:
	std::vector<int> number;
	bool sign;

public:
	//Constructer
	BigInt();
	BigInt(int);
	BigInt(long long);
	BigInt(std::string);
	BigInt(float);
	BigInt(double);
	BigInt(long double);
	~BigInt();

	//Allocation


	//Addition
	BigInt add(BigInt b);
	BigInt add(int);
	BigInt add(long long);
	BigInt add(std::string);
	BigInt add(float);
	BigInt add(double);
	BigInt add(long double);

	// Other utility methods
	bool getSign();
	std::string getNumber();
	void negate();
	void PRINT();

	// Math functions
};

