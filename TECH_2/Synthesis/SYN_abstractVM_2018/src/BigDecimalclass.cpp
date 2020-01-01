/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** BigDecimalclass
*/
#include <iostream>
#include <algorithm>
#include "Factory.h"

BigDecimalclass::~BigDecimalclass()
{

}

BigDecimalclass::BigDecimalclass(const std::string &value) : IOperand()
{
	_value = value;
	reverse(_value.begin(), _value.end());
}

std::string BigDecimalclass::toString() const
{
	std::string result = _value;

	reverse(result.begin(), result.end());
	result = Factory::delFillingZero(result);
	if (result.size() > 200)
		return(result.substr(0, 200));
	return (result);
}

eOperandType BigDecimalclass::getType() const
{
    return (_type);
}

char BigDecimalclass::addChar(const char &a, const char &b, int &carry) const
{
	int result = (a - '0') + (b - '0') + carry;
	
	if (carry != 0)
		carry = 0;
	if (result >= 10) {
		carry = result % 10;
		result /= 10;
	}
	std::cout << "result [" << (char)(result + '0') << "]" << std::endl;
	return(result + '0');
}

char BigDecimalclass::subChar(const char &a, const char &b, int &carry) const
{
	int result;

	if ((a - '0') - ((b - '0') + carry) < 0) {
		result = (10 + (a - '0')) - ((b - '0') + carry);
		carry = 1;
		return (result + '0');
	}
	result = (a - '0') - ((b - '0') + carry);
	carry = 0;
	return (result + '0');
}

std::string BigDecimalclass::fillNumberWithZero(const std::string &str, const size_t &size, const bool &reversed) const
{
	std::string to_reverse;

	if (!reversed) {
		to_reverse = str;
		reverse(to_reverse.begin(), to_reverse.end());
		return (to_reverse + std::string(size - to_reverse.size(), '0'));
	}
	return (str + std::string(size - str.size(), '0'));
}

IOperand *BigDecimalclass::operator+(const IOperand &rhs) const
{
	std::string result;
	int carry = 0;
	size_t max_size = rhs.toString().size() > _value.size() ? rhs.toString().size() : _value.size();

	std::string rhs_reverse = fillNumberWithZero(rhs.toString(), max_size, false);
	std::string value_reverse = fillNumberWithZero(_value, max_size, true);

	for (size_t i = 0; i < rhs_reverse.size(); i += 1) {
		if (rhs_reverse[i] == '.') {
			result += '.';
			continue;
		}
		result += addChar(value_reverse[i], rhs_reverse[i], carry);
	}
	reverse(result.begin(), result.end());
	return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), result));
}

IOperand *BigDecimalclass::operator-(const IOperand &rhs) const
{
	std::string result;
	int carry = 0;
	size_t max_size = rhs.toString().size() > _value.size() ? rhs.toString().size() : _value.size();

	std::string rhs_reverse = fillNumberWithZero(rhs.toString(), max_size, false);
	std::string value_reverse = fillNumberWithZero(_value, max_size, true);

	for (size_t i = 0; i < rhs_reverse.size(); i += 1) {
		if (rhs_reverse[i] == '.') {
			result += '.';
			continue;
		}
		result += subChar(value_reverse[i], rhs_reverse[i], carry);
	}
	reverse(result.begin(), result.end());
	return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), result));
}

IOperand *BigDecimalclass::operator*(const IOperand &rhs) const
{
	return (nullptr);
}

IOperand *BigDecimalclass::operator/(const IOperand &rhs) const
{
	return (nullptr);
}

IOperand *BigDecimalclass::operator%(const IOperand &rhs) const
{
	return (nullptr);
}
