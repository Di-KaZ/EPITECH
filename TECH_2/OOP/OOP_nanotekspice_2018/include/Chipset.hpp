/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Chipset.hpp
*/

#include "IComponent.hpp"
#include "Pin.hpp"
#include "Parser.hpp"
#include "LogicGate.hpp"
#include "LogicNot.hpp"
#include "LogicAnd.hpp"
#include "LogicOr.hpp"
#include "LogicXor.hpp"
#include "LogicNor.hpp"
#include "LogicNand.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"
#include <map>

namespace nts
{
	class Chipset : public IComponent {
		public:
			Chipset();
			Chipset(const std::vector<std::string> &input, const std::vector<std::string> &output, std::vector<std::string> logic);
			~Chipset();
			nts::Tristate compute(size_t pin = 1);
			void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
			void dump() const;
			void initializePins(const std::vector<std::string> &temp);
			Pin *getPinFromName(const std::string &name);
			void displayOutputs();
			void createComponent(const std::string &gate_conf, std::vector<std::string> &links);
			void setLogicName(std::vector<std::string> logics);
		private:
			void create4069(const std::vector<Pin *> &links);
			void create4081(const std::vector<Pin *> &links);
			void create4071(const std::vector<Pin *> &links);
			void create4030(const std::vector<Pin *> &links);
			void create4001(const std::vector<Pin *> &links);
			void create4011(const std::vector<Pin *> &links);
			void sortPins(const std::vector<std::string> &links);
			std::vector<std::string> _input_name;
			std::vector<std::string> _output_name;
			Pin *_sorted_pins[15] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
			std::map<std::string, Pin *> _pins;
			std::vector<LogicGate *> _logics;
			std::vector<std::string> _logics_name;
	};
} // nts

bool unhandled_param(std::string path_name);
