/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

namespace nts
{
	Clock::Clock()
	{

	}

	Clock::~Clock()
	{

	}

	nts::Tristate Clock::compute(size_t pin)
	{
		(void) pin;
		static int first_p = false;

		if (!first_p) {
			first_p = true;
			return (nts::Tristate::FALSE);
		}
		if (_state == nts::Tristate::TRUE)
			_state = nts::Tristate::FALSE;
		if (_state == nts::Tristate::FALSE)
			_state = nts::Tristate::TRUE;
		return (nts::Tristate::FALSE);
	}

	void Clock::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
	{
		(void) pin;
		(void) other;
		(void) otherPin;
	}

	void Clock::dump() const
	{
		std::cout << "Clock - value " << this->_state << std::endl;
		
	}

	void Clock::setState(nts::Tristate)
	{
		static int first_p = false;

		if (!first_p) {
			first_p = true;
			return;
		}
		if (_state == nts::Tristate::TRUE)
			_state = nts::Tristate::FALSE;
		if (_state == nts::Tristate::FALSE)
			_state = nts::Tristate::TRUE;
	}
}