/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Output.cpp
*/

#include "Output.hpp"

namespace nts
{
	Output::Output()
	{

	}

	Output::~Output()
	{

	}

	nts::Tristate Output::compute(size_t pin)
	{
		(void) pin;

		return (nts::Tristate::FALSE);
	}

	void Output::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
	{
		(void) pin;
		(void) other;
		(void) otherPin;
	}

	void Output::dump() const
	{
		std::cout << "Output - value " << this->_state << std::endl;
		
	}
}