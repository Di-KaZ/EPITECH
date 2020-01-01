/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Int32class
*/

#include "Factory.h"
#include "int32class.hpp"

Int32class::Int32class(const std::string &value) : IOperand()
{
	if (std::stoi(value) > std::numeric_limits<std::int32_t>::max())
		throw IOperandOverflow();
	if (std::stoi(value) < std::numeric_limits<std::int32_t>::min())
		throw IOperandUnderFlow();
	_value = std::stoi(value);
}

Int32class::~Int32class()
{

}

std::string Int32class::toString() const
{
	return (std::to_string(_value));
}

eOperandType Int32class::getType() const
{
	return (_type);
}

IOperand *Int32class::operator+(const IOperand &rhs) const
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

IOperand *Int32class::operator-(const IOperand &rhs) const
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

IOperand *Int32class::operator*(const IOperand &rhs) const
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

IOperand *Int32class::operator/(const IOperand &rhs) const
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

IOperand *Int32class::operator%(const IOperand &rhs) const
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
