/*
** EPITECH PROJECT, 2018
** new_nanotekspice
** File description:
** Parser.hpp
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

namespace nts
{
	class Parser {
		public:
			Parser(const std::string &nts_filepath);
			~Parser();
			const std::vector<std::string> &getInputs() const;
			const std::vector<std::string> &getOutputs() const;
			const std::vector<std::string> &getlinks() const;
			const std::vector<std::string> &getlogics() const;
		private:
			void findInputsLine();
			void findOutputsLine();
			void findLinksLine();
			void findLogicsLine();
			std::vector<std::string> _file_str;
			std::vector<std::string> _outputs;
			std::vector<std::string> _inputs;
			std::vector<std::string> _logics;
			std::vector<std::string> _links;
	};
} // nts