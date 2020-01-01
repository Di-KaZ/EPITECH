/*
** EPITECH PROJECT, 2019
** parsingfile
** File description:
** parsingfile
*/

#include "parsingFile.hpp"
#include "Command.hpp"
#include "instruction.hpp"

parsingFile::parsingFile(const std::string& _str)
{
    openFile(_str);
}

parsingFile::parsingFile()
{
    openFile(" ");
}

parsingFile::~parsingFile(){}

void parsingFile::parsregex()
{
    std::smatch s;
    std::string stock;
    std::regex erreur("^(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit|push|assert)(\\s+(int32|double|float|bigdecimal)(.*[0-9]).*)?");
    for (size_t i = 0; i < _map.size(); i++) {
        if (_map[i].empty() != true) {
            if ((std::regex_search(_map[i], s, erreur)) == true) {
                stock = s.str();
            } else {
                throw ParsingFileSyntax();
            }
        }
    }
}

void parsingFile::openFile(const std::string& str)
{
    instruction vm;
    _file.open(str);
    if (_file) {
        while(getline(_file, _line))
            if (_line.find(";") == std::string::npos) {
                _map.push_back(_line);
                parsregex();
			Command test(_line);
			vm.executeInstruction(test);
            }
    }
    else if (!_file) {
        while(42)
            if (getline(std::cin, _line)) {
                if (_line == "")
                    throw ParsingFileSyntax();
                 if (_line.find(";;") != std::string::npos)
                    return;
                if (_line.find(";") == std::string::npos) {
                  _map.push_back(_line);
                  parsregex();
			Command test(_line);
			vm.executeInstruction(test);
                }
            }
     } else
        throw ParsingFileNotFound();
}