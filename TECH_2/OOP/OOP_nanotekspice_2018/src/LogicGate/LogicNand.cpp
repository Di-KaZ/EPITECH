/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicNand.cpp
*/

#include "LogicNand.hpp"

namespace nts
{
	LogicNand::LogicNand()
	{

	}

	LogicNand::~LogicNand()
	{
		
	}
	
	void LogicNand::setLink(Pin *pin, nts::Utility utility)
	{
		if (utility == nts::Utility::OUTPUT) {
			this->_output = pin;
		}
		if (utility == nts::Utility::INPUT && this->_inputs.size() < 2) {
			this->_inputs.push_back(dynamic_cast<Input *>(pin));
		}
	}

	void LogicNand::compute()
	{
		if (this->_inputs[0]->getState() == nts::Tristate::TRUE &&
				this->_inputs[1]->getState() == nts::Tristate::TRUE)
			this->_output->setState(nts::Tristate::FALSE);
		else
			this->_output->setState(nts::Tristate::TRUE);
	}
}