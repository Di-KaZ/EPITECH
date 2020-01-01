/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** False.cpp
*/

#include "False.hpp"

namespace nts
{
	False::False()
	{

	}

	False::~False()
	{

	}

	nts::Tristate False::compute(size_t pin)
	{
		(void) pin;

		return (nts::Tristate::FALSE);
	}

	void False::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
	{
		(void) pin;
		(void) other;
		(void) otherPin;
	}

	void False::dump() const
	{
		std::cout << "False - value " << this->_state << std::endl;
		
	}
}