#include "BigInt.h"



BigInt::BigInt()
{
}

BigInt::BigInt(int n)
{
	if (n < 0) {
		sign = 1;
		n *= (-1);
	}
	else sign = 0;

	while (n) {
		number.push_back(n % 10);
		n = n / 10;
	}

	std::reverse(number.begin(), number.end());
}

BigInt::BigInt(long long n)
{
	if (n < 0) {
		sign = 1;
		n *= (-1);
	}
	else sign = 0;

	while (n) {
		number.push_back(n % 10);
		n = n / 10;
	}

	std::reverse(number.begin(), number.end());
}

BigInt::BigInt(std::string n)
{
	if (n[0] == '-') {
		sign = 1;
		n.erase(n.begin() + 0);
	}
	else sign = 0;

	while(n[0] == '0')	n.erase(n.begin() + 0);
	
	int i=0;
	while (i < n.size()) {
		number.push_back(n[i++] - '0');
	}
}

BigInt::BigInt(float fn)
{
	int n = fn;

	if (n < 0) {
		sign = 1;
		n *= (-1);
	}
	else sign = 0;

	while (n) {
		number.push_back(n % 10);
		n = n / 10;
	}

	std::reverse(number.begin(), number.end());
}

BigInt::BigInt(double dn)
{
	long long int n = dn;

	if (n < 0) {
		sign = 1;
		n *= (-1);
	}
	else sign = 0;

	while (n) {
		number.push_back(n % 10);
		n = n / 10;
	}

	std::reverse(number.begin(), number.end());
}

BigInt::BigInt(long double dn)
{
	unsigned long long int n = dn;

	if (n < 0) {
		sign = 1;
		n *= (-1);
	}
	else sign = 0;

	while (n) {
		number.push_back(n % 10);
		n = n / 10;
	}

	std::reverse(number.begin(), number.end());
}

BigInt::~BigInt()
{
}

BigInt BigInt::add(BigInt b)
{
	/*if (b.sign) {
		sub(b);
		return 0;
	}*/

	int tempNumber;
	int reminder = 0;
	BigInt tempAns;

	int index = number.size() - 1;
	int indexb = b.number.size() - 1;

	while (index >= 0 && indexb >=0) {
		tempNumber = number[index] + b.number[indexb] + reminder;
		tempAns.number.push_back(tempNumber % 10);
		reminder = tempNumber / 10;

		index--;
		indexb--;
	}

	/*int i = 0;
	while (i < tempAns.number.size()) std::cout << (tempAns.number[i++]);
	std::cout << std::endl;*/
	
	while (index >= 0) {
		tempNumber = number[index--] + reminder;
		tempAns.number.push_back(tempNumber % 10);
		reminder = tempNumber / 10;
	}

	while (indexb >= 0) {
		tempNumber = b.number[indexb--] + reminder;
		tempAns.number.push_back(tempNumber % 10);
		reminder = tempNumber / 10;
	}

	if (reminder)	tempAns.number.push_back(reminder);

	reverse(tempAns.number.begin(), tempAns.number.end());

	return tempAns;
}

BigInt BigInt::add(int b)
{
	BigInt temp;
	if (b < 0) {
		sign = 1;
		b *= (-1);
	}
	else sign = 0;

	while (b) {
		temp.number.push_back(b % 10);
		b = b / 10;
	}

	std::reverse(temp.number.begin(), temp.number.end());
	temp = add(temp);
	return temp;
}

BigInt BigInt::add(long long b)
{
	BigInt temp;
	if (b < 0) {
		sign = 1;
		b *= (-1);
	}
	else sign = 0;

	while (b) {
		temp.number.push_back(b % 10);
		b = b / 10;
	}

	std::reverse(temp.number.begin(), temp.number.end());
	temp = add(temp);
	return temp;
}

BigInt BigInt::add(std::string n)
{
	BigInt temp;
	if (n[0] == '-') {
		sign = 1;
		n.erase(n.begin() + 0);
	}
	else sign = 0;

	while (n[0] == '0')	n.erase(n.begin() + 0);

	int i = 0;
	while (i < n.size()) {
		temp.number.push_back(n[i++] - '0');
	}
	temp = add(temp);
	return temp;
}

BigInt BigInt::add(float fb)
{
	long long int b = fb;
	BigInt temp;
	if (b < 0) {
		sign = 1;
		b *= (-1);
	}
	else sign = 0;

	while (b) {
		temp.number.push_back(b % 10);
		b = b / 10;
	}

	std::reverse(temp.number.begin(), temp.number.end());
	temp = add(temp);
	return temp;
}

BigInt BigInt::add(double fd)
{
	long long int b = fd;
	BigInt temp;
	if (b < 0) {
		sign = 1;
		b *= (-1);
	}
	else sign = 0;

	while (b) {
		temp.number.push_back(b % 10);
		b = b / 10;
	}

	std::reverse(temp.number.begin(), temp.number.end());
	temp = add(temp);
	return temp;
}

BigInt BigInt::add(long double fd)
{
	unsigned long long int b = fd;
	BigInt temp;
	if (b < 0) {
		sign = 1;
		b *= (-1);
	}
	else sign = 0;

	while (b) {
		temp.number.push_back(b % 10);
		b = b / 10;
	}

	std::reverse(temp.number.begin(), temp.number.end());
	temp = add(temp);
	return temp;
}

void BigInt::PRINT()
{
	int i = 0;
	while (i < number.size()) std::cout << (number[i++]);
	std::cout << std::endl;
}
