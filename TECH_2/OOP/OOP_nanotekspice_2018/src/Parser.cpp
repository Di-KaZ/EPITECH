/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace nts
{
	Parser::Parser(const std::string &nts_filepath)
	{
		std::ifstream file;
		std::string line;

		file.open(nts_filepath);
		while (std::getline(file, line))
			if (!line.empty() && line[0] != '#')
				this->_file_str.push_back(line);
		findInputsLine();
		findOutputsLine();
		findLinksLine();
		findLogicsLine();
		file.close();
	}

	Parser::~Parser()
	{

	}

	const std::vector<std::string> &Parser::getInputs() const
	{
		return (this->_inputs);
	}

	const std::vector<std::string> &Parser::getOutputs() const
	{
		return (this->_outputs);
	}

	const std::vector<std::string> &Parser::getlinks() const
	{
		return (this->_links);
	}

	const std::vector<std::string> &Parser::getlogics() const
	{
		return (this->_logics);
	}

	void Parser::findInputsLine()
	{
		for (size_t i = 0; i < this->_file_str.size(); i += 1) {
			if (this->_file_str[i].find("input") == 0)
				this->_inputs.push_back(this->_file_str[i]);
			if (this->_file_str[i].find("clock") == 0)
				this->_inputs.push_back(this->_file_str[i]);
			if (this->_file_str[i].find("true") == 0)
				this->_inputs.push_back(this->_file_str[i]);
			if (this->_file_str[i].find("false") == 0)
				this->_inputs.push_back(this->_file_str[i]);
		}
	}

	void Parser::findOutputsLine()
	{
		for (size_t i = 0; i < this->_file_str.size(); i += 1) {
			if (this->_file_str[i].find("output") == 0)
				this->_outputs.push_back(this->_file_str[i]);
		}
	}

	void Parser::findLinksLine()
	{
		for (size_t i = 0; i < this->_file_str.size(); i += 1) {
			if (this->_file_str[i].find(".links:") == 0) {
				i += 1;
				while (i < this->_file_str.size()) {
					this->_links.push_back(this->_file_str[i]);
					i += 1;
				}
			}
		}
	}

	void Parser::findLogicsLine()
	{
		std::vector<std::string> tab_of_logic;
		tab_of_logic.push_back("4081");
		tab_of_logic.push_back("4001");
		tab_of_logic.push_back("4008");
		tab_of_logic.push_back("4040");
		tab_of_logic.push_back("4514");
		tab_of_logic.push_back("4017");
		tab_of_logic.push_back("4069");
		tab_of_logic.push_back("4071");
		tab_of_logic.push_back("4030");
		tab_of_logic.push_back("4011");

		for (size_t i = 0; i != this->_file_str.size(); i += 1) {
			for (size_t j = 0; j != tab_of_logic.size(); j += 1)
				if (this->_file_str[i].find(tab_of_logic[j]) == 0)
					this->_logics.push_back(this->_file_str[i]);
		}
	}
} // nts