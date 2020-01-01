/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Clock.hpp
*/

#include "Pin.hpp"
#include "Input.hpp"

namespace nts
{
	class Clock : public Input {
		public:
			Clock();
			~Clock();
			nts::Tristate compute(size_t pin = 1);
			void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
			void dump() const;
			void setState(nts::Tristate state);
	};
} // nts