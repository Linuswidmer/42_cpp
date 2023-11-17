#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "------------------ SUBJECT --------------------\n";
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}


	{
	    std::cout << "------------------ EXAMPLE 1 --------------------\n";
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
   		std::cout << "Stack is empty: " << (stack.empty() ? "true" : "false") << std::endl;
		std::cout << std::endl;
	}


	{
    	std::cout << "------------------ EXAMPLE 2 --------------------\n";
		MutantStack<std::string> stack_string;

		stack_string.push("hello");
		stack_string.push("world");
		stack_string.push("this");
		stack_string.push("is");
		stack_string.push("a");
		stack_string.push("test");

		stack_string.pop();

		std::cout << "Stack size is " << stack_string.size() << std::endl;
	
		{
			MutantStack<std::string>::const_iterator it = stack_string.begin();
			MutantStack<std::string>::const_iterator it_end = stack_string.end();
			std::cout << "printing with iterator" << std::endl;
			while (it != it_end)
			{
				std::cout << *it << " ";
				it++;
			}
		}
		std::cout << std::endl;

    	std::cout << "Stack is empty: " << (stack_string.empty() ? "true" : "false") << std::endl;

		std::cout << std::endl;

    	std::cout << "--------------- COPY / ASSIGNMENT ----------------\n";

		MutantStack<std::string> stack_copy(stack_string);
		{
			MutantStack<std::string>::const_iterator it = stack_copy.begin();
			MutantStack<std::string>::const_iterator it_end = stack_copy.end();
			std::cout << "Copying the string stack\n";
			while (it != it_end)
			{
				std::cout << *it << " ";
				it++;
			}
		}
		std::cout << std::endl;

		MutantStack<std::string> stack_new = stack_string;
		{
			MutantStack<std::string>::const_iterator it = stack_copy.begin();
			MutantStack<std::string>::const_iterator it_end = stack_copy.end();
			std::cout << "Assigning the string stack\n";
			while (it != it_end)
			{
				std::cout << *it << " ";
				it++;
			}
		}
		std::cout << std::endl;

	}
}