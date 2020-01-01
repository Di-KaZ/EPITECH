/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** int8class
*/

#include "IOperand.hpp"

#pragma once

class Int8class : public IOperand
{
	public:
		Int8class(const std::string &value);
		virtual ~Int8class();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		eOperandType _type = eOperandType::int8;
		std::int8_t _value;
};
