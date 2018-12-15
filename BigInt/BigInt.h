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
	void setSign(bool);
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

	BigInt operator + (BigInt b);
	template <typename T>
	BigInt operator + (T);

	//Substraction
	BigInt sub(BigInt b);
	BigInt sub(int);
	BigInt sub(long long);
	BigInt sub(std::string);
	BigInt sub(float);
	BigInt sub(double);
	BigInt sub(long double);

	BigInt operator - (BigInt b);
	template <typename T>
	BigInt operator - (T);

	//Multiplication
	BigInt mul(BigInt b);

	//Comparisons
	bool operator == (BigInt);
	bool operator != (BigInt);
	bool operator < (BigInt);
	bool operator <= (BigInt);
	bool operator > (BigInt);
	bool operator >= (BigInt);

	//Unary Operators
	BigInt operator ++();		//prefix
	BigInt operator ++(int);	//postfix
	BigInt operator --();		//prefix
	BigInt operator --(int);	//postfix

	BigInt abs();
};
