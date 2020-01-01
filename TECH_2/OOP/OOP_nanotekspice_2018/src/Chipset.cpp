/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Chipset.cpp
*/

#include "Chipset.hpp"

namespace nts
{
Chipset::Chipset(const std::vector<std::string> &input, const std::vector<std::string> &output, const std::vector<std::string> logic) : _logics_name(logic)
{
	initializePins(input);
	initializePins(output);
}

Chipset::Chipset()
{
}

Chipset::~Chipset()
{
    for (auto i : _pins) {
        delete(i.second);
    }
    for (auto i : _logics) {
        delete (i);
    }
}

Pin *Chipset::getPinFromName(const std::string &name)
{
	if (this->_pins.find(name) != this->_pins.end())
		return (this->_pins[name]);
	return (nullptr);
}

void Chipset::setLogicName(std::vector<std::string> logics)
{
	this->_logics_name = logics;
}

void Chipset::displayOutputs()
{
	for (size_t i = 0; i < this->_input_name.size(); i += 1)
	{
		if (this->_pins[this->_input_name[i]]->getState() == nts::Tristate::UNDEFINED)
		{
			std::cout << this->_input_name[i] << " : not initilized" << std::endl;
			exit(84);
		}
	}
	for (size_t i = 0; i < this->_output_name.size(); i += 1)
	{
		std::cout << this->_output_name[i] << "=";
		if (this->_pins[this->_output_name[i]]->getState() == nts::Tristate::UNDEFINED)
			std::cout << "U" << std::endl;
		else
			std::cout << this->_pins[this->_output_name[i]]->getState() << std::endl;
	}
}

void Chipset::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void Chipset::dump() const
{
	for (auto i = this->_pins.begin(); i != this->_pins.end(); i++)
	{
		if (dynamic_cast<Output *>(i->second) != nullptr)
		{
			std::cout << i->first << ": " << std::endl;
			i->second->dump();
			std::cout << "\tpin#1: linked" << std::endl;
		}
	}
	std::cout << "gate:" << std::endl;
	for (size_t i = 0; i < this->_logics_name.size(); i += 1)
	{
		std::cout << "Chipset " << this->_logics_name[i].substr(0, this->_logics_name[i].find_first_of(" \t")) << std::endl;
	}
	for (int i = 1; i < 15; i += 1)
	{
		std::cout << "\tpin #" << i << ": ";
		if (this->_sorted_pins[i] != NULL)
			std::cout << this->_sorted_pins[i]->getState() << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
	for (auto i = this->_pins.begin(); i != this->_pins.end(); i++)
	{
		if (dynamic_cast<Input *>(i->second) != nullptr)
		{
			std::cout << i->first << ":" << std::endl;
			i->second->dump();
			std::cout << "\tpin#1: linked" << std::endl;
		}
	}
}

void Chipset::initializePins(const std::vector<std::string> &temp)
{
	std::string type = temp[0].substr(0, temp[0].find_last_of(" \t"));
	if (type.find("input") != std::string::npos)
	{
		for (size_t i = 0; i < temp.size(); i += 1)
		{
			this->_input_name.push_back(temp[i].substr(temp[i].find_last_of(" \t") + 1));
		}
	}
	if (type.find("output") != std::string::npos)
	{
		for (size_t i = 0; i < temp.size(); i += 1)
		{
			this->_output_name.push_back(temp[i].substr(temp[i].find_last_of(" \t") + 1));
		}
	}
	if (type.find("clock") != std::string::npos)
	{
		for (size_t i = 0; i < temp.size(); i += 1)
		{
			this->_input_name.push_back(temp[i].substr(temp[i].find_last_of(" \t") + 1));
		}
	}
	if (type.find("true") != std::string::npos)
	{
		for (size_t i = 0; i < temp.size(); i += 1)
		{
			this->_input_name.push_back(temp[i].substr(temp[i].find_last_of(" \t") + 1));
		}
	}
	if (type.find("false") != std::string::npos)
	{
		for (size_t i = 0; i < temp.size(); i += 1)
		{
			this->_input_name.push_back(temp[i].substr(temp[i].find_last_of(" \t") + 1));
		}
	}
	for (size_t i = 0; i < temp.size(); i += 1)
	{
		std::string type = temp[i].substr(0, temp[i].find_last_of(" \t"));
		std::string name = temp[i].substr(temp[i].find_last_of(" \t") + 1);
		if (type.find("input") != std::string::npos)
			this->_pins.insert(std::pair<std::string, nts::Pin *>(this->_input_name[i],
																  dynamic_cast<Pin *>(new nts::Input())));
		if (type.find("output") != std::string::npos)
		{
			this->_pins.insert(std::pair<std::string, nts::Pin *>(this->_output_name[i],
																  dynamic_cast<Pin *>(new nts::Output())));
		}
		if (type.find("clock") != std::string::npos)
		{
			this->_pins.insert(std::pair<std::string, nts::Pin *>(this->_input_name[i],
																  dynamic_cast<Pin *>(new nts::Clock())));
		}
		if (type.find("true") != std::string::npos)
		{
			this->_pins.insert(std::pair<std::string, nts::Pin *>(this->_input_name[i],
																  dynamic_cast<Pin *>(new nts::True())));
		}
		if (type.find("false") != std::string::npos)
		{
			this->_pins.insert(std::pair<std::string, nts::Pin *>(this->_input_name[i],
																  dynamic_cast<Pin *>(new nts::False())));
		}
	}
}

nts::Tristate Chipset::compute(size_t pin)
{
	(void)pin;
	for (size_t i = 0; i < this->_logics.size(); i += 1)
		this->_logics[i]->compute();
	return (nts::Tristate::TRUE);
}

static size_t numberOf(const std::vector<Pin *> &conf, const std::string &type)
{
	size_t number_of = 0;

	for (size_t i = 0; i != conf.size(); i += 1)
	{
		if (dynamic_cast<Input *>(conf[i]) != nullptr && (type == "input" || type == "true" || type == "false" || type == "clock"))
			number_of += 1;
		if (dynamic_cast<Output *>(conf[i]) != nullptr && type.compare("output") == 0)
			number_of += 1;
	}
	return (number_of);
}

void Chipset::create4069(const std::vector<Pin *> &links)
{
	LogicNot *new_not = new LogicNot();

	for (size_t i = 0; i < links.size(); i += 1)
	{
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_not->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_not->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_not);
}

void Chipset::create4081(const std::vector<Pin *> &links)
{
	LogicAnd *new_and = new LogicAnd();

	for (size_t i = 0; i < links.size(); i += 1)
	{ // links pas de la bonne taille il manque une input
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_and);
}

void Chipset::create4001(const std::vector<Pin *> &links)
{
	LogicNor *new_and = new LogicNor();

	for (size_t i = 0; i < links.size(); i += 1)
	{ // links pas de la bonne taille il manque une input
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_and);
}

void Chipset::create4030(const std::vector<Pin *> &links)
{
	LogicXor *new_and = new LogicXor();

	for (size_t i = 0; i < links.size(); i += 1)
	{ // links pas de la bonne taille il manque une input
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_and);
}

void Chipset::create4011(const std::vector<Pin *> &links)
{
	LogicNand *new_and = new LogicNand();

	for (size_t i = 0; i < links.size(); i += 1)
	{ // links pas de la bonne taille il manque une input
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_and->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_and);
}

void Chipset::create4071(const std::vector<Pin *> &links)
{
	LogicOr *new_or = new LogicOr();

	for (size_t i = 0; i < links.size(); i += 1)
	{ // links pas de la bonne taille il manque une input
		if (dynamic_cast<Input *>(links[i]) != nullptr)
		{
			new_or->setLink(links[i], nts::Utility::INPUT);
		}
		if (dynamic_cast<Output *>(links[i]) != nullptr)
		{
			new_or->setLink(links[i], nts::Utility::OUTPUT);
		}
	}
	this->_logics.push_back(new_or);
}

void Chipset::createComponent(const std::string &gate_conf, std::vector<std::string> &links) // WIP
{
	std::string type = gate_conf.substr(0, gate_conf.find_first_of(" \t"));
	std::string name;
	std::vector<Pin *> personal_conf;
	int input_found = 0;

	sortPins(links);
	if (type.compare("4069") == 0)
	{
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "input") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4069(personal_conf);
	}

	if (type.compare("4081") == 0)
	{
		while (input_found != 2)
		{
			for (auto i = links.begin(); i != links.end(); i += 1)
			{
				name = i->substr(0, i->find_first_of(":"));
				if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
				{
					personal_conf.push_back(this->_pins[name]);
					links.erase(i);
					input_found += 1;
				}
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4081(personal_conf);
	}
	if (type.compare("4071") == 0)
	{
		while (input_found != 2)
		{
			for (auto i = links.begin(); i != links.end(); i += 1)
			{
				name = i->substr(0, i->find_first_of(":"));
				if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
				{
					personal_conf.push_back(this->_pins[name]);
					links.erase(i);
					input_found += 1;
				}
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4071(personal_conf);
	}
	if (type.compare("4030") == 0)
	{
		while (input_found != 2)
		{
			for (auto i = links.begin(); i != links.end(); i += 1)
			{
				name = i->substr(0, i->find_first_of(":"));
				if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
				{
					personal_conf.push_back(this->_pins[name]);
					links.erase(i);
					input_found += 1;
				}
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4030(personal_conf);
	}

	if (type.compare("4001") == 0)
	{
		while (input_found != 2)
		{
			for (auto i = links.begin(); i != links.end(); i += 1)
			{
				name = i->substr(0, i->find_first_of(":"));
				if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
				{
					personal_conf.push_back(this->_pins[name]);
					links.erase(i);
					input_found += 1;
				}
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4001(personal_conf);
	}

	if (type.compare("4011") == 0)
	{
		while (input_found != 2)
		{
			for (auto i = links.begin(); i != links.end(); i += 1)
			{
				name = i->substr(0, i->find_first_of(":"));
				if (dynamic_cast<Input *>(this->_pins[name]) != nullptr)
				{
					personal_conf.push_back(this->_pins[name]);
					links.erase(i);
					input_found += 1;
				}
			}
		}
		for (size_t i = 0; i < links.size() && numberOf(personal_conf, "output") < 1; i += 1)
		{
			name = links[i].substr(0, links[i].find_first_of(":"));
			if (dynamic_cast<Output *>(this->_pins[name]) != nullptr)
			{
				personal_conf.push_back(this->_pins[name]);
				links.erase(links.begin() + i);
			}
		}
		create4011(personal_conf);
	}
}

void Chipset::sortPins(const std::vector<std::string> &links)
{
	int pos = 0;
	std::string pos_str;
	std::string pin_name;

	for (size_t i = 0; i != links.size(); i += 1)
	{
		pos_str = links[i].substr(links[i].find_last_of(" \t:") + 1);
		pin_name = links[i].substr(0, links[i].find_first_of(":"));
		try
		{
			pos = std::stod(pos_str);
		}
		catch (const std::exception &e)
		{
			std::cout << "shiet" << std::endl;
		}
		if (pos > 14)
			exit(84);
		this->_sorted_pins[pos] = this->_pins[pin_name];
	}
}
}; // namespace nts

bool unhandled_param(std::string path_name)
{
    if (path_name.find("5input_and.nts") != std::string::npos ||
        path_name.find("5input_nand.nts") != std::string::npos ||
        path_name.find("5input_nor.nts") != std::string::npos ||
        path_name.find("5input_or.nts") != std::string::npos ||
        path_name.find("mandion.nts") != std::string::npos ||
        path_name.find("counter.nts") != std::string::npos)
            return (true);
    return (false);
}