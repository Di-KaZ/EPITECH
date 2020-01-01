/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Doubleclass
*/

#include "IOperand.hpp"

#pragma once

class Doubleclass : public IOperand
{
	public:
		Doubleclass(const std::string &value);
		virtual ~Doubleclass();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		eOperandType _type = eOperandType::Double;
		double _value;
};
