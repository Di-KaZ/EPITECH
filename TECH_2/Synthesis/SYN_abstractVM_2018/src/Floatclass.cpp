/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Floatclass
*/

#include "Factory.h"
#include "Floatclass.hpp"

Floatclass::Floatclass(const std::string &value) : IOperand()
{
	if (std::stod(value) > std::numeric_limits<float>::max())
		throw IOperandOverflow();
	if (std::stod(value) < std::numeric_limits<float>::min())
		throw IOperandUnderFlow();
    _value = std::stof(value);
}

Floatclass::~Floatclass()
{

}

std::string Floatclass::toString() const
{
	std::string result = std::to_string(_value);
	if (result.size() > 7)
		result = result.substr(0, 7);
	return (Factory::delFillingZero(result));
}

eOperandType Floatclass::getType() const
{
	return (_type);
}

IOperand *Floatclass::operator+(const IOperand &rhs) const
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

IOperand *Floatclass::operator-(const IOperand &rhs) const
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

IOperand *Floatclass::operator*(const IOperand &rhs) const
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

IOperand *Floatclass::operator/(const IOperand &rhs) const
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

IOperand *Floatclass::operator%(const IOperand &rhs) const
{
	throw IOperandModuloOnFloat();
}
