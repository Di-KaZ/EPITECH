/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** int32class
*/

#include "IOperand.hpp"

#pragma once

class Int32class : public IOperand
{
	public:
		Int32class(const std::string &type);
		virtual ~Int32class();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		eOperandType _type = eOperandType::int32;
		std::int32_t _value;
};
