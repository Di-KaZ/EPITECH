#include "Command.hpp"
#include <iostream>
#include "ParsingException.hpp"

static const std::map<std::string, eOperandType> opereand_type =
{
	{"int8", eOperandType::int8},
	{"int16", eOperandType::int16},
	{"int32", eOperandType::int32},
	{"double", eOperandType::Double},
	{"float", eOperandType::Float},
	{"bigdecimal", eOperandType::BigDecimal}
};

Command::Command(const std::string &commandline)
{
	std::string commandline_cpy = commandline;
	std::string type;

	commandline_cpy = commandline_cpy.substr(commandline_cpy.find(' ') + 1);
	_command = commandline.substr(0, commandline.find(' '));
	if (_command != "push" && _command != "assert" && _command != "load" && _command != "store")
		return;
	type = commandline_cpy.substr(0, commandline_cpy.find('('));
	try {
		_type = opereand_type.at(type);
	} catch (const std::exception &e) {
		throw ParsingUknownType();
	}
	_value = commandline.substr(commandline.find('('), commandline.find_last_of("0123456789"));
	_value.erase(_value.begin());
	_value.erase(_value.end() - 1);
}

Command::~Command()
{

}

const std::string &Command::getCommand() const
{
	return (_command);
}

const std::string &Command::getValue() const
{
	return (_value);
}

const eOperandType &Command::getType() const
{
	return (_type);
}
