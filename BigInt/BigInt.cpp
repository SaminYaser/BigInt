#include "BigInt.h"


//Constructor
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

	while(n[0] == '0' && n.size() != 1)	n.erase(n.begin() + 0);
	
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

void BigInt::setSign(bool b)
{
	sign = b;
}

//Utility Functions
bool BigInt::getSign()
{
	return sign;
}

std::string BigInt::getNumber()
{
	std::string tempString;
	if (getSign()) {
		tempString += '-';
	}
	for (int i = 0; i < number.size(); i++) {
		tempString += '0' + number[i];
	}
	return tempString;
}

void BigInt::negate()
{
	sign = !sign;
}

void BigInt::PRINT()
{
	/*
	int i = 0;
	if (getSign())	std::cout << "-";
	while (i < number.size()) std::cout << number[i++];
	std::cout << std::endl;
	*/

	std::cout << getNumber() << std::endl;
}

//Addition
BigInt BigInt::add(BigInt b)
{
	if (getSign() != b.getSign()) {
		b.negate();
		return sub(b);
	}

	int tempNumber;
	int reminder = 0;
	BigInt tempAns;

	if (getSign()) tempAns.sign = 1;

	int index = number.size() - 1;
	int indexb = b.number.size() - 1;

	while (index >= 0 && indexb >=0) {
		tempNumber = number[index] + b.number[indexb] + reminder;
		tempAns.number.push_back(tempNumber % 10);
		reminder = tempNumber / 10;

		index--;
		indexb--;
	}
	
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
	BigInt temp(b);
	return add(temp);
}

BigInt BigInt::add(long long b)
{
	BigInt temp(b);
	return add(temp);
}

BigInt BigInt::add(std::string n)
{
	BigInt temp(n);
	return add(temp);
}

BigInt BigInt::add(float fb)
{
	BigInt temp(fb);
	return add(temp);
}

BigInt BigInt::add(double fd)
{
	BigInt temp(fd);
	return add(temp);
}

BigInt BigInt::add(long double fd)
{
	BigInt temp(fd);
	return add(temp);
}

BigInt BigInt::operator+(BigInt b)
{
	return this->add(b);
}

template<typename T>
BigInt BigInt::operator+(T b)
{
	BigInt temp(b);
	return this->add(temp);
}

//Substraction
BigInt BigInt::sub(BigInt b)
{
	BigInt tempa = *this;
	
	if (tempa.sign != b.sign) {
		b.negate();
		return tempa.add(b);
	}

	int tempNumber;
	int reminder = 0;
	BigInt tempAns;

	if (tempa.getSign()) {
		tempAns.sign = tempa.getSign();
	}

	int index = tempa.number.size() - 1;
	int indexb = b.number.size() - 1;

	if (tempa.abs() < b.abs()) {
		std::swap(tempa, b);
		std::swap(index, indexb);
		tempAns.setSign(!b.getSign());
	}

	while (index > 0 && indexb >= 0) {
		tempNumber = tempa.number[index] - b.number[indexb];
		if (tempNumber < 0) {
			tempNumber += 10;
			tempa.number[index - 1] -= 1;
		}
		tempAns.number.push_back(tempNumber);

		index--;
		indexb--;
	}

	while (index >= 0) {
		if(indexb == 0) tempNumber = tempa.number[index] - b.number[indexb--];
		else			tempNumber = tempa.number[index];
		if (tempNumber < 0 && index != 0) {
			tempNumber += 10;
			tempa.number[index - 1] -= 1;
		}
		else if (tempNumber < 0 && index == 0)	tempNumber *= -1; //I don't know if it's right
		tempAns.number.push_back(tempNumber);

		index--;
	}

	std::reverse(tempAns.number.begin(), tempAns.number.end());

	while (tempAns.number[0] == 0 && tempAns.number.size() != 1) tempAns.number.erase(tempAns.number.begin() + 0);
	if (tempAns.number[0] == 0)	tempAns.setSign(0);

	return tempAns;
}

BigInt BigInt::sub(int b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::sub(long long b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::sub(std::string b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::sub(float b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::sub(double b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::sub(long double b)
{
	BigInt temp(b);
	return sub(b);
}

BigInt BigInt::operator-(BigInt b)
{
	return sub(b);
}

template<typename T>
BigInt BigInt::operator-(T b)
{
	BigInt temp(b);
	return sub(temp);
}


BigInt BigInt::mul(BigInt b)
{
	BigInt temp = *this;
	return temp;
}

//Comparisons
bool BigInt::operator==(BigInt b)
{
	if (sign != b.sign)	return false;

	int index = number.size();
	int indexb = b.number.size();

	if (index != indexb)	return false;

	int i = 0;
	while (i < index && number[i] == b.number[i]) i++;

	if (i == index) return true;
	return false;
}

bool BigInt::operator!=(BigInt b)
{
	return !(*this == b);
}

bool BigInt::operator<(BigInt b)
{
	if (sign == 0 && b.sign == 1)	return false;
	else if (sign == 1 && b.sign == 0)	return true;

	bool flag = sign;
	bool ans = 0;

	int index = number.size();
	int indexb = b.number.size();

	if (index > indexb)	ans = 0;
	else if (index < indexb)	ans = 1;

	if (index != indexb) {
		if (flag) return !ans;
		return ans;
	}

	int i = 0;
	while (i < index && number[i] == b.number[i]) i++;
	
	if (i == index) return false;
	else if (number[i] < b.number[i]) ans = 1;
	else if(number[i] > b.number[i]) ans = 0;
	
	if (flag) return !ans;
	return ans;
}

bool BigInt::operator<=(BigInt b)
{
	return (*this < b || *this == b);
}

bool BigInt::operator>(BigInt b)
{
	return !(*this < b);
}

bool BigInt::operator>=(BigInt b)
{
	return (*this > b || *this == b);
}

BigInt BigInt::operator++()
{
	*this = *this + 1;
	return *this;
}

BigInt BigInt::operator++(int)
{
	BigInt before = *this;
	*this = *this + 1;
	return before;
}

BigInt BigInt::operator--()
{
	*this = *this - 1;
	return *this;
}

BigInt BigInt::operator--(int)
{
	BigInt before = *this;
	*this = *this - 1;
	return before;
}

BigInt BigInt::abs()
{
	BigInt temp = *this;
	temp.sign = 0;
	return temp;
}

