/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicNot.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicNot : public LogicGate {
		public:
			LogicNot();
			~LogicNot();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}