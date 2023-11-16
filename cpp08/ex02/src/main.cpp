#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <string>

int	main(void)
{
	{
		std::cout << "EXAMPLE 1: INTEGER\n";
		MutantStack<int> stack;

		stack.push(21);
		stack.push(22);
		stack.push(23);
		stack.push(24);
		int num=0;
		stack.push(num);
		
		stack.pop();
		stack.pop();

		std::cout << "Stack size is " << stack.size() << std::endl;
		std::cout << "Stack is empty: " << stack.empty() << std::endl;

		// iterate

		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator it_end = stack.end();

		std::cout << "printing with iterator" << std::endl;
		while (it != it_end)
		{
			std::cout << *it << " ";
			it++;
		}

		std::cout << std::endl << "printing with top" << std::endl;
		while (!stack.empty()) {
			std::cout << stack.top() <<" ";
			stack.pop();
		}
		std::cout << std::endl;
	}


	{
		std::cout << std::endl << "EXAMPLE 2: STRING\n";
		MutantStack<std::string> stack;

		stack.push("hello");
		stack.push("world");
		stack.push("this");
		stack.push("is");
		stack.push("a");
		stack.push("test");

		stack.pop();

		std::cout << "Stack size is " << stack.size() << std::endl;
	
		MutantStack<std::string>::const_iterator it = stack.begin();
		MutantStack<std::string>::const_iterator it_end = stack.end();
		std::cout << "printing with iterator" << std::endl;
		while (it != it_end)
		{
			std::cout << *it << " ";
			it++;
		}

		std::cout << std::endl << "printing with top" << std::endl;
		while (!stack.empty()) {
			std::cout << stack.top() <<" ";
			stack.pop();
		}
		std::cout << std::endl;

		std::cout << std::endl << "Stack is empty: " << stack.empty() << std::endl;
	}

	{
		// Copy and assignment
	}
}