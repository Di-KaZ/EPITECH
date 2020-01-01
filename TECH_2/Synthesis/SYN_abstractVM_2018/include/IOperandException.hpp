#include <exception>
#pragma once

struct IOperandEmptyStack : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] empty stack";
	}
};


struct IOperandAssertFalse : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Assert intruction was false";
	}
};

struct IOperandNoteEnoughArgument : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Note enough argument";
	}
};

struct IOperandOverflow : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Overflow.";
	}
};

struct IOperandUnderFlow : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Underflow.";
	}
};


struct IOperandDivisionByZero : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Division by Zero.";
	}
};

struct IOperandModuloOnFloat : public std::exception
{
	const char *what() const throw ()
	{
		return "[ERROR] Modulo on floating point value.";
	}
};
