/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicAnd.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicAnd : public LogicGate {
		public:
			LogicAnd();
			~LogicAnd();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}