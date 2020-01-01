/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** int8class
*/

#include "Factory.h"
#include "int8class.hpp"

Int8class::Int8class(const std::string &value) : IOperand()
{
	if (std::stoi(value) > std::numeric_limits<std::int8_t>::max())
		throw IOperandOverflow();
	if (std::stoi(value) < std::numeric_limits<std::int8_t>::min())
		throw IOperandUnderFlow();
	_value = std::stoi(value);
}

Int16class::~Int16class()
{

}

std::string Int8class::toString() const
{
	return (std::to_string(_value));
}

eOperandType Int8class::getType() const
{
	return (_type);
}

IOperand *Int8class::operator+(const IOperand &rhs) const
{
	if (Factory::isFloating(rhs.getType())) {
		float result = _value + std::stod(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	} else {
        	int result = _value + std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}

IOperand *Int8class::operator-(const IOperand &rhs) const
{
	if (Factory::isFloating(rhs.getType())) {
		float result = _value - std::stod(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	} else {
		int result = _value - std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
    return (nullptr);
}

IOperand *Int8class::operator*(const IOperand &rhs) const
{
	if (Factory::isFloating(rhs.getType())) {
		float result = _value * std::stod(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	} else {
		int result = _value * std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}

IOperand *Int8class::operator/(const IOperand &rhs) const
{
	if (std::stoi(rhs.toString()) == 0)
		throw IOperandDivisionByZero();
	else if (Factory::isFloating(rhs.getType())) {
		float result = _value / std::stod(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	} else {
		int result = _value / std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}

IOperand *Int8class::operator%(const IOperand &rhs) const
{
	if (std::stoi(rhs.toString()) == 0) {
		throw IOperandDivisionByZero();
	} else if (Factory::isFloating(rhs.getType())) {
		throw IOperandModuloOnFloat();
	}
	else {
		int result = _value % std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}
