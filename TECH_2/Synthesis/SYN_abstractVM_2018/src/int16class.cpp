/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Int16class
*/

#include "Factory.h"
#include "int16class.hpp"

Int16class::Int16class(const std::string &value) : IOperand()
{
	if (std::stoi(value) > std::numeric_limits<std::int16_t>::max())
		throw IOperandOverflow();
	if (std::stoi(value) < std::numeric_limits<std::int16_t>::min())
		throw IOperandUnderFlow();
	_value = std::stoi(value);
}

std::string Int16class::toString() const
{
	return (std::to_string(_value));
}

eOperandType Int16class::getType() const
{
	return (_type);
}

IOperand *Int16class::operator+(const IOperand &rhs) const
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

IOperand *Int16class::operator-(const IOperand &rhs) const
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

IOperand *Int16class::operator*(const IOperand &rhs) const
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

IOperand *Int16class::operator/(const IOperand &rhs) const
{
	if (std::stoi(rhs.toString()) == 0)
		throw "Error there";
	else if (Factory::isFloating(rhs.getType())) {
		float result = _value / std::stod(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	} else {
		int result = _value / std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}

IOperand *Int16class::operator%(const IOperand &rhs) const
{
	if (std::stoi(rhs.toString()) == 0 || Factory::isFloating(rhs.getType())) {
		throw "Error there";
	} else {
		int result = _value % std::stoi(rhs.toString());
		return (Factory::createOperand(Factory::getMostPrecise(*this, rhs), std::to_string(result)));
	}
	return (nullptr);
}
