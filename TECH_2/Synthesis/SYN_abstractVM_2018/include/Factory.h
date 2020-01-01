/*
** EPITECH PROJECT, 2019
** abstractWM
** File description:
** Factory
*/

#include "IOperand.hpp"
#include "int8class.hpp"
#include "int16class.hpp"
#include "int32class.hpp"
#include "Doubleclass.hpp"
#include "Floatclass.hpp"
#include "BigDecimalclass.hpp"
#include <cstdint>
#include <map>
#include <vector>
#include <limits>

#pragma once

typedef IOperand *(*createPtr)(const std::string &);

class Factory
{
	public:
		static IOperand *createOperand(eOperandType type, const std::string &value);
		static eOperandType getMostPrecise(const IOperand &a, const IOperand &b);
		static bool isFloating(const eOperandType &type);
		static std::string delFillingZero(const std::string &val);
	private:
		static IOperand *createInt8(const std::string &value);
		static IOperand *createInt16(const std::string &value);
		static IOperand *createInt32(const std::string &value);
		static IOperand *createFloat(const std::string &value);
		static IOperand *createDouble(const std::string &value);
		static IOperand *createBigDecimal(const std::string &value);
};
