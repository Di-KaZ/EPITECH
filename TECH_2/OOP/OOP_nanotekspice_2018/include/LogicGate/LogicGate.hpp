/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicGate.hpp
*/

#pragma once
#include "Pin.hpp"
#include "Input.hpp"
#include "Output.hpp"

namespace nts
{
	enum Utility {
		INPUT = 0,
		OUTPUT = 1
	};
	class LogicGate {
		public:
			virtual ~LogicGate() = default;
			virtual void compute() = 0;
			virtual void setLink(Pin *pin, nts::Utility utility) = 0;
		protected:
			std::vector<Input *> _inputs;
			Pin *_output;
	};
}