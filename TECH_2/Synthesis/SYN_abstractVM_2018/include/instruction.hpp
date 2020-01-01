/*
** EPITECH PROJECT, 2018
** $PROJECT
** File description:
** instruction.hpp
*/
#ifndef SYN_ABSTRACTVM_2018_INSTRUCTION_HPP
#define SYN_ABSTRACTVM_2018_INSTRUCTION_HPP

#include <iostream>
#include "IOperand.hpp"
#include <stack>
#include "IOperandException.hpp"
#include "Command.hpp"



class instruction {
	public:
	instruction();
	virtual ~instruction();
	void executeInstruction(const Command &command);
	private:
	std::stack<IOperand const *> stack;
	void pop(const Command &command);
	void exit(const Command &command);
	void put(const Command &command);
	void push(const Command &command);
	void dump(const Command &command);
	void assert(const Command &command);
	void clear(const Command &command);
	void print(const Command &command);
	void add(const Command &command);
	void sub(const Command &command);
	void div(const Command &command);
	void mod(const Command &command);
	void mul(const Command &command);
	void dup(const Command &command);
	void swap(const Command &command);
};

#endif //SYN_ABSTRACTVM_2018_INSTRUCTION_HPP
