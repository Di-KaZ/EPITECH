/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** int16class
*/

#include "IOperand.hpp"

#pragma once

class Int16class : public IOperand
{
	public:
		Int16class(const std::string &type);
		virtual ~Int16class();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		eOperandType _type = eOperandType::int16;
		std::int16_t _value;
};
