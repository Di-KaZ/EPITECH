/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Input.cpp
*/

#include "Input.hpp"

namespace nts
{
	Input::Input()
	{

	}

	Input::~Input()
	{

	}

	nts::Tristate Input::compute(size_t pin)
	{
		(void) pin;

		return (nts::Tristate::FALSE);
	}

	void Input::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
	{
		(void) pin;
		(void) other;
		(void) otherPin;
	}

	void Input::dump() const
	{
		std::cout << "Input - value " << this->_state << std::endl;
		
	}
}