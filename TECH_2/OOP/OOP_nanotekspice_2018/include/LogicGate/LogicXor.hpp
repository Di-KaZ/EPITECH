/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicXor.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicXor : public LogicGate {
		public:
			LogicXor();
			~LogicXor();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}