/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Doubleclass
*/

#include "Factory.h"
#include "Doubleclass.hpp"

Doubleclass::~Doubleclass()
{

}

Doubleclass::Doubleclass(const std::string &value) : IOperand()
{
	if (std::stold(value) > std::numeric_limits<double>::max())
		throw IOperandOverflow();
	if (std::stold(value) < std::numeric_limits<double>::min())
		throw IOperandUnderFlow();
	_value = std::stod(value);
}

std::string Doubleclass::toString() const
{
	std::string result = std::to_string(_value);

	if (result.size() > 15)
		result = result.substr(0, 15);
	return (Factory::delFillingZero(result));
}

eOperandType Doubleclass::getType() const
{
	return (_type);
}

IOperand *Doubleclass::operator+(const IOperand &rhs) const
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

IOperand *Doubleclass::operator-(const IOperand &rhs) const
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

IOperand *Doubleclass::operator*(const IOperand &rhs) const
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

IOperand *Doubleclass::operator/(const IOperand &rhs) const
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

IOperand *Doubleclass::operator%(const IOperand &rhs) const
{
	throw IOperandModuloOnFloat();
}
