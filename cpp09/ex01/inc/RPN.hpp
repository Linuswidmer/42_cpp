#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <algorithm>
# include <stdlib.h>
# include <cctype>

class RPN
{
public:
	// public methods
	bool		calculate(const std::string &rpn, float *result);

	//Getters and Setters

	// Constructors, Assignment, Destructors
	RPN(void);
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN(void);

private:
	bool	_calcStack(const std::string &op);

	// Data
	std::stack<float>	_stack;
};

#endif