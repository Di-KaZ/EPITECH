/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Factory
*/

#include "Factory.h"
#include <iostream>

bool Factory::isFloating(const eOperandType &type)
{
    return (type == eOperandType::Double || type == eOperandType::Float);
}

std::string Factory::delFillingZero(const std::string &val)
{
	if (val[val.size() - 1] == '0')
		return (delFillingZero(val.substr(0, val.size() - 1)));
	return(val);
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    static const std::map<eOperandType, createPtr> creator_ptr =
    {
            {eOperandType::int8, createInt8},
            {eOperandType::int16, createInt16},
            {eOperandType::int32, createInt32},
            {eOperandType::Float, createFloat},
            {eOperandType::Double, createDouble},
            {eOperandType::BigDecimal, createBigDecimal}, 
            {eOperandType::BigDecimal, nullptr}
    };
    return (creator_ptr.at(type)(value));
}

eOperandType Factory::getMostPrecise(const IOperand&a, const IOperand &b)
{
    const std::vector<eOperandType> best_precision =
    {
        eOperandType::BigDecimal,
        eOperandType::Double,
        eOperandType::Float,
        eOperandType::int32,
        eOperandType::int16,
        eOperandType::int8
    };

    for (auto i : best_precision) {
        if (i == a.getType() || i == b.getType())
            return (i);
    }
    return (eOperandType::BigDecimal);
}

IOperand *Factory::createInt8(const std::string &value)
{
    return (new Int8class(value));
}

IOperand *Factory::createInt16(const std::string &value)
{
    return (new Int16class(value));
}

IOperand *Factory::createInt32(const std::string &value)
{
    return (new Int32class(value));
}

IOperand *Factory::createFloat(const std::string &value)
{
    return (new Floatclass(value));
}

IOperand *Factory::createDouble(const std::string &value)
{
    return (new Doubleclass(value));
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    return (new BigDecimalclass(value));
}
