/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** LogicOr.hpp
*/

#pragma once
#include "Pin.hpp"
#include "LogicGate.hpp"

namespace nts
{
	class LogicOr : public LogicGate {
		public:
			LogicOr();
			~LogicOr();
			void setLink(Pin *pin, nts::Utility utility);
			void compute();
	};
}