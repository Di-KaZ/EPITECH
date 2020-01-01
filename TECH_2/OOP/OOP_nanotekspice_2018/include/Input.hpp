/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Input.hpp
*/

#include "Pin.hpp"
#pragma once

namespace nts
{
	class Input : public Pin {
		public:
			Input();
			~Input();
			virtual nts::Tristate compute(size_t pin = 1);
			void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
			virtual void dump() const;
	};
} // nts