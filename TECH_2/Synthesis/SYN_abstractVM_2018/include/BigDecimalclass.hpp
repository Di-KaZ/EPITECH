/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** BigDecimalclass
*/

#include "IOperand.hpp"

#pragma once

class BigDecimalclass : public IOperand
{
	public:
		BigDecimalclass(const std::string &value);
		virtual ~BigDecimalclass();
		std::string toString() const;
		eOperandType getType() const;
		IOperand *operator+(const IOperand &rhs) const;
		IOperand *operator-(const IOperand &rhs) const;
		IOperand *operator*(const IOperand &rhs) const;
		IOperand *operator/(const IOperand &rhs) const;
		IOperand *operator%(const IOperand &rhs) const;
	private:
		std::string fillNumberWithZero(const std::string &str, const size_t &size, const bool &revese = true) const;
		char addChar(const char &a, const char &b, int &carry) const;
		char subChar(const char &a, const char &b, int &carry) const;
		eOperandType _type = eOperandType::BigDecimal;
		std::string _value;
};
