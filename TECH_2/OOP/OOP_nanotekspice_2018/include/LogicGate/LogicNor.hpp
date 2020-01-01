/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicNor.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicNor : public LogicGate {
		public:
			LogicNor();
			~LogicNor();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}