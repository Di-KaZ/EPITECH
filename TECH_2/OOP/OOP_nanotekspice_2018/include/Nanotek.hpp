/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Nanotek.hpp
*/

#include "Parser.hpp"
#include "Chipset.hpp"
#include <csignal>

namespace nts {
	class Nanotek {
		public:
			Nanotek(nts::Parser *parser);
			~Nanotek();
			void run();
			void iniValue(int ac, const char **av);
		private:
			void display();
			void loop();
			void dump();
			void simulate();
			void inputEqValue(std::string &line);
			std::string isStillEnoughToMake(std::vector<std::string> &gates, const std::vector<std::string> &links);
			nts::Parser *_parser = nullptr;
			nts::Chipset _chipset;
	};
} // nts
