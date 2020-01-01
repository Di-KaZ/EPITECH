/*
** EPITECH PROJECT, 2019
** parsingFile
** File description:
** parsingFile
*/


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <regex>
#include "ParsingException.hpp"

class parsingFile
{
private:
    std::vector<std::string> _map;
    std::string _line;
     std::ifstream _file;
public:
    parsingFile(const std::string&);
    parsingFile();
    ~parsingFile();
    void openFile(const std::string&);
    void parsregex();
};
