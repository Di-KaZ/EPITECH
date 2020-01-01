/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Floatclass
*/

#include "IOperand.hpp"

#pragma once

class Floatclass : public IOperand
{
	public:
		Floatclass(const std::string &vlaue);
		~Floatclass();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		eOperandType _type = eOperandType::Float;
		float _value;
};
