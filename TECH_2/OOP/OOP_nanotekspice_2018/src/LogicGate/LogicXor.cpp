/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicXor.cpp
*/

#include "LogicXor.hpp"

namespace nts
{
	LogicXor::LogicXor()
	{

	}

	LogicXor::~LogicXor()
	{
		
	}
	
	void LogicXor::setLink(Pin *pin, nts::Utility utility)
	{
		if (utility == nts::Utility::OUTPUT) {
			this->_output = pin;
		}
		if (utility == nts::Utility::INPUT && this->_inputs.size() < 2) {
			this->_inputs.push_back(dynamic_cast<Input *>(pin));
		}
	}

	void LogicXor::compute()
	{
		if (this->_inputs[0]->getState() == nts::Tristate::FALSE &&
				this->_inputs[1]->getState() == nts::Tristate::TRUE)
			this->_output->setState(nts::Tristate::TRUE);
		else if (this->_inputs[0]->getState() == nts::Tristate::TRUE &&
				this->_inputs[1]->getState() == nts::Tristate::FALSE)
			this->_output->setState(nts::Tristate::TRUE);
		else
			this->_output->setState(nts::Tristate::FALSE);
	}
}