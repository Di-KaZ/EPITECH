/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Output.hpp
*/

#include "Pin.hpp"

namespace nts
{
	class Output : public Pin {
		public:
			Output();
			~Output();
			nts::Tristate compute(size_t pin = 1);
			void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
			void dump() const;
	};
} // nts