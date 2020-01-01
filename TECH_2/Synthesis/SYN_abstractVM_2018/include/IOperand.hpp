/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** IOperand
*/

#include <string>
#include "IOperandException.hpp"
#pragma once


enum class eOperandType {
    int8,
    int16,
    int32,
    Float,
    Double,
    BigDecimal
};

class IOperand
{
    public:
	IOperand() {}
        virtual ~IOperand() {}
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
};
