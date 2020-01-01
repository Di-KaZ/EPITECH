/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Nanotek.cpp
*/

#include "Nanotek.hpp"
#include "unistd.h"

namespace nts
{
	static bool __loop__ = true; // used to sighandle SIGINT and stop infinite loop

	Nanotek::Nanotek(Parser *parse)
	{
		this->_parser = parse;
		auto temp_links = this->_parser->getlinks();
		auto temp_gates = this->_parser->getlogics();
		this->_chipset.initializePins(parse->getInputs());
		this->_chipset.initializePins(parse->getOutputs());
		while (temp_links.size()) {
			if (isStillEnoughToMake(temp_gates, temp_links).compare("none") == 0)
				break;
			this->_chipset.createComponent(isStillEnoughToMake(temp_gates, temp_links), temp_links);
		}
		this->_chipset.setLogicName(this->_parser->getlogics());
	}

	Nanotek::~Nanotek()
	{
        
	}

	void Nanotek::iniValue(int ac, const char **av)
	{
		std::string pin_name;
		std::string value_str;
		std::string value; 
		int state = 0;

		for (int i = 2; i < ac; i += 1) {
			value = av[i];
			pin_name = value.substr(0, value.find("="));
			value_str = value.substr(value.find("=") + 1);
			try {
				state = std::stoi(value_str);
			} catch (const std::exception &e) {
				std::cerr << "Invalid value (must be 0 or 1)" << std::endl;
				exit(84);
			}
			if (dynamic_cast<Input *>(this->_chipset.getPinFromName(pin_name)) == nullptr) {
				std::cerr << pin_name << " : invalid input." << std::endl;
				exit(84);
			}
			if (dynamic_cast<True *>(this->_chipset.getPinFromName(pin_name)) != nullptr) {
				std::cerr << pin_name << " : is always true." << std::endl;
				exit(84);
			}
			if (dynamic_cast<False *>(this->_chipset.getPinFromName(pin_name)) != nullptr) {
				std::cerr << pin_name << " : is always false." << std::endl;
				exit(84);
			}
			if (state == 0)
				this->_chipset.getPinFromName(pin_name)->setState(nts::Tristate::FALSE);
			else if (state == 1)
				this->_chipset.getPinFromName(pin_name)->setState(nts::Tristate::TRUE);
			else
				std::cerr << "Invalid value (must be 0 or 1)" << std::endl;
		}
	}

	std::string Nanotek::isStillEnoughToMake(std::vector<std::string> &gates, const std::vector<std::string> &links)
	{
		size_t input_number = 0;
		std::vector<std::string> chipsets;
		std::vector<size_t> input_necessary;
		std::string name;

		chipsets.push_back("4069");
		chipsets.push_back("4081");
		chipsets.push_back("4071");
		chipsets.push_back("4030");
		chipsets.push_back("4001");
		chipsets.push_back("4011");
		input_necessary.push_back(1);
		input_necessary.push_back(2);
		input_necessary.push_back(2);
		input_necessary.push_back(2);
		input_necessary.push_back(2);
		input_necessary.push_back(2);
		
		if (!gates.empty())
			name = gates[0].substr(0, gates[0].find_first_of(" \t"));
		for (size_t i = 0; i < links.size(); i += 1) {
			std::string name_pin = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Input *>(this->_chipset.getPinFromName(name_pin)) != nullptr) input_number += 1;
			if (dynamic_cast<Output *>(this->_chipset.getPinFromName(name_pin)) != nullptr) input_number += 1;
		}
		for (size_t i = 0; i < chipsets.size(); i += 1) {
			if (name.compare(chipsets[i]) == 0 && input_number < input_necessary[i])
				gates.erase(gates.begin());
		}
		if (!gates.empty())
			return (gates[0]);
		name = "none";
		return (name);
	}

	void Nanotek::run()
	{
		std::string line;
	
		this->_chipset.compute();
		this->_chipset.displayOutputs();
		std::cout << "> ";
		while (std::getline(std::cin, line) && line.compare("exit")) {
			if (line.compare("display") == 0)
				display();
			else if (line.find("=") != std::string::npos)
				inputEqValue(line);
			else if (line.compare("simulate") == 0)
				simulate();
			else if (line.compare("loop") == 0)
				loop();
			else if (line.compare("dump") == 0)
				dump();
			else
				std::cerr << line << ": invalid command." << std::endl;
			std::cout << "> ";
		}
	}

	void Nanotek::display()
	{
		this->_chipset.displayOutputs();
	}

	void Nanotek::inputEqValue(std::string &value)
	{
		std::string pin_name = value.substr(0, value.find("="));
		std::string value_str = value.substr(value.find("=") + 1);
		int state = 0;

		try {
			state = std::stoi(value_str);
		} catch (const std::exception &e) {
			std::cerr << "Invalid value (must be 0 or 1)" << std::endl;
		}
		if (dynamic_cast<Input *>(this->_chipset.getPinFromName(pin_name)) == nullptr) {
			std::cerr << pin_name << ": Invalid input." << std::endl;
		}
		if (state == 0)
			this->_chipset.getPinFromName(pin_name)->setState(nts::Tristate::FALSE);
		else if (state == 1)
			this->_chipset.getPinFromName(pin_name)->setState(nts::Tristate::TRUE);
		else
			std::cerr << "Invalid value (must be 0 or 1)" << std::endl;
	}

	void Nanotek::simulate()
	{
		this->_chipset.compute();
	}

	static void stop_loop(int sig) // sig handler
	{
		(void) sig;
		__loop__ = false;
	}

	void Nanotek::loop()
	{
		__loop__ = true;

		signal(SIGINT, stop_loop);
		while (__loop__) {
			this->_chipset.compute();
		}
		std::cout << std::endl;
		signal(SIGINT, SIG_DFL);
	}

	void Nanotek::dump()
	{
		this->_chipset.dump();
	}
} // nts