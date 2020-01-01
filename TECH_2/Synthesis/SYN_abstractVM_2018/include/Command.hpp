#include <map>
#include "IOperand.hpp"

#pragma once

class Command 
{
	public:
		Command(const std::string &commandline);
		virtual ~Command();
		const std::string &getCommand() const;
		const std::string &getValue() const;
		const eOperandType &getType() const;
	private:
		std::string _command;
		eOperandType _type;
		std::string _value;
};
