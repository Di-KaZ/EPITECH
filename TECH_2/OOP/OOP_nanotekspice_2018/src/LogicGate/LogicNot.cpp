/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicNot.cpp
*/

#include "LogicNot.hpp"

namespace nts
{
	LogicNot::LogicNot()
	{

	}
	
	LogicNot::~LogicNot()
	{

	}

	void LogicNot::setLink(Pin *pin, nts::Utility utility)
	{
		if (utility == nts::Utility::OUTPUT) {
			this->_output = pin;
		}
		if (utility == nts::Utility::INPUT && this->_inputs.size() < 1) {
			this->_inputs.push_back(dynamic_cast<Input *>(pin));
		}
	}

	void LogicNot::compute()
	{
		if (this->_inputs[0]->getState() == nts::Tristate::TRUE)
			this->_output->setState(nts::Tristate::FALSE);
		if (this->_inputs[0]->getState() == nts::Tristate::FALSE)
			this->_output->setState(nts::Tristate::TRUE);
	}
}