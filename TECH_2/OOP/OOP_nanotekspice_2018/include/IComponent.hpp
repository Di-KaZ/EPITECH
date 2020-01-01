/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Icomponent.cpp
*/

#pragma once

#include <vector>
#include <iostream>
#include <string>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = 1,
		FALSE = 0
	};
	class IComponent {
		public:
			virtual ~IComponent() = default;
			virtual nts::Tristate compute(size_t pin = 1) = 0;
			virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
			virtual void dump() const = 0;
	};	
} // nts
