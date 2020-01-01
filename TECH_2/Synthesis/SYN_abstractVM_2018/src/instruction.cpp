/*
** EPITECH PROJECT, 2018
** $PROJECT
** File description:
** instruction.cpp
*/
#include "instruction.hpp"
#include "Factory.h"

instruction::instruction()
{

}

instruction::~instruction()
{

}

void instruction::pop(const Command &)
{

	if(stack.empty())
		throw IOperandEmptyStack();
	stack.pop();
}

void instruction::exit(const Command &)
{
	std::exit(0);
}

void instruction::executeInstruction(const Command &command)
{
	std::map<std::string, void(instruction::*)(const Command &)> commmands_ptr =
	{
		{"push", &instruction::push},
		{"pop", &instruction::pop},
		{"assert", &instruction::assert},
		{"exit", &instruction::exit},
		{"clear", &instruction::clear},
		{"print", &instruction::print},
		{"add", &instruction::add},
		{"sub", &instruction::sub},
		{"div", &instruction::div},
		{"mul", &instruction::mul},
		{"mod", &instruction::mod},
		{"swap", &instruction::swap},
		{"dump", &instruction::dump},
		{"dup", &instruction::dup}
	};
	(this->*commmands_ptr[command.getCommand()])(command);
}

void instruction::push(const Command &command)
{
	stack.push(Factory::createOperand(command.getType(), command.getValue()));
}

void instruction::assert(const Command &command)
{
	const IOperand* target = stack.top();
	if (stack.empty())
	throw IOperandAssertFalse();
	if (target->getType() != command.getType() || target->toString() != command.getValue())
		throw IOperandAssertFalse();
}

void instruction::clear(const Command &)
{
	while (!stack.empty())
		stack.pop();
}

void instruction::print(const Command &)
{
	if (stack.empty())
		throw IOperandEmptyStack();
	std::cout << static_cast<char>(std::stoi(stack.top()->toString())) << std::endl;
}

void instruction::add(const Command &)
{
	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();

	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();

	stack.push(*first + *second);
	delete (first);
	delete (second);
}

void instruction::sub(const Command &)
{
	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();

	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();
	stack.push(*second - *first);
	delete (first);
	delete (second);
}

void instruction::div(const Command &)
{
	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();

	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();
	stack.push(*second / *first);
	delete (first);
	delete (second);
}

void instruction::mod(const Command &)
{
	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();
	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();
	stack.push(*second % *first);
	delete (first);
	delete (second);
}

void instruction::mul(const Command &)
{
	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();
	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();
	stack.push(*first * *second);
	delete (first);
	delete (second);
}

void instruction::swap(const Command &)
{

	if (stack.size() < 2)
		throw IOperandNoteEnoughArgument();
	IOperand const *first;
	IOperand const *second;

	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();
	stack.push(first);
	stack.push(second);
	delete (first);
	delete (second);
}

void instruction::dump(const Command &)
{
	if (stack.size() == 0)
		return;
	std::stack<const IOperand*> substack(stack);
	while (stack.size() != 0)
	{
		std::cout << (stack.top()->toString()) << std::endl;
		stack.pop();
	}
	substack.swap(stack);
}

void instruction::dup(const Command &)
{
	IOperand const *tmp = stack.top();
	stack.push(tmp);
}
