/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** True.cpp
*/

#include "True.hpp"

namespace nts
{
	True::True()
	{

	}

	True::~True()
	{

	}

	nts::Tristate True::compute(size_t pin)
	{
		(void) pin;

		return (nts::Tristate::FALSE);
	}

	void True::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
	{
		(void) pin;
		(void) other;
		(void) otherPin;
	}

	void True::dump() const
	{
		std::cout << "True - value " << this->_state << std::endl;
		
	}
}