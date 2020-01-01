/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Pin.hpp
*/

#pragma once
#include "IComponent.hpp"

namespace nts
{
	class Pin : public IComponent {
		public:
			Pin()  { };
			~Pin() { };
			virtual nts::Tristate compute(size_t pin = 1) = 0;
			virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
			virtual void dump() const = 0;
			virtual void setState(nts::Tristate state) {this->_state = state; };
			nts::Tristate getState() const { return (this->_state); };
		protected:
			nts::Tristate _state = nts::Tristate::UNDEFINED;
	};
} // nts