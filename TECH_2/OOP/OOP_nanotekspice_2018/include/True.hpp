/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** True.hpp
*/

#include "Input.hpp"
#pragma once

namespace nts
{
	class True : public Input {
		public:
			True();
			~True();
			virtual nts::Tristate compute(size_t pin = 1);
			void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
			virtual void dump() const;
			void setState(nts::Tristate) { this->_state = nts::Tristate::TRUE; }
	};
} // nts