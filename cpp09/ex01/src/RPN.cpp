#include "RPN.hpp"

/*****************************************************************************/
/*                              PUBLIC METHODS                               */
/*****************************************************************************/

/*
*	takes a string in Reverse Polish Notation (RPN) and calculates the result
	RETURNS:
		- true if the calculation was successful
		- false if the calculation was not successful
*/
bool	RPN::calculate(const std::string &rpn, float *result)
{
	std::istringstream	input(rpn);
	std::string			content;

	while ( input >> content )
	{
		if (isdigit(content[0]))
			_stack.push(atof(content.c_str()));
		else
		{
			if ( !_calcStack(content))
			{
				std::cerr << "Error: encountered invalid symbol " << content << std::endl;
				return (false);
			}
		}
	}
	if ( _stack.size() != 1 )
	{
		std::cerr << "Error: stack size is bigger than 1 => too few operands" << std::endl;
		return (false);
	}
	*result = _stack.top();
	return (true);
}

/*
*	Takes the top 2 numbers of the stack and calculates the result 
*	with the operator
	RETURNS:
		- true if the operator is valid
		- false if the operator is invalid
*/
bool	RPN::_calcStack(const std::string &op) 
{
	if ( _stack.size() < 2 )
		return (false);
	float	num1 = _stack.top();
	_stack.pop();
	float	num2 = _stack.top();
	_stack.pop();

	if ( op == "+" )
		_stack.push(num2 + num1);
	else if ( op == "-" )
		_stack.push(num2 - num1);
	else if ( op == "*")
		_stack.push(num2 * num1);
	else if ( op == "/")
		_stack.push(num2 / num1);
	else
		return (false);
	return (true);
}


/*****************************************************************************/
/*                        DEFAULT CON-/DESTRUCTOR                            */
/*****************************************************************************/

RPN::RPN(void)
{}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN(void)
{}
