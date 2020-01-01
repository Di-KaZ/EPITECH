/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicNand.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicNand : public LogicGate {
		public:
			LogicNand();
			~LogicNand();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}