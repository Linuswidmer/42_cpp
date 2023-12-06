#include "PmergeMe.hpp"

/*****************************************************************************/
/*                              PUBLIC METHODS                               */
/*****************************************************************************/

void	PmergeMe::sort()
{
	std::cout << "STEP 3: sort larger elements from each pair" << std::endl;
	std::sort(_vec.begin(), _vec.end());
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << "(" << _vec[i].first << ", " << _vec[i].second << ") \n";
	}

	std::cout << "STEP 4: Create the main chain and the pend" << std::endl;
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (i == 0)
		{
			_mainChain.push_back(_vec[i].second);
			_mainChain.push_back(_vec[i].first);
		}
		else
		{
			_mainChain.push_back(_vec[i].first);
			_pend.push_back(_vec[i].second);
		}
	}

	// print main chain
	std::cout << "Main chain: ";
	for (size_t i = 0; i < _mainChain.size(); i++)
	{
		std::cout << _mainChain[i] << " ";
	}
	std::cout << std::endl;
	// print pend
	std::cout << "Pend: ";
	for (size_t i = 0; i < _pend.size(); i++)
	{
		std::cout << _pend[i] << " ";
	}
}

/*****************************************************************************/
/*                        DEFAULT CON-/DESTRUCTOR                            */
/*****************************************************************************/

PmergeMe::PmergeMe(const std::string &numStr)
{
	int					num1;
	int					num2;
	std::stringstream	ss( (std::string(numStr)) );

	// check if input is valid, if all numbers are positive etc
	// check that there is at least two numbers (or three?)

	while (ss >> num1)
	{
		if (ss >> num2)
		{
			if (num1 >= num2)
				_vec.push_back(std::make_pair(num1, num2));
			else
				_vec.push_back(std::make_pair(num2, num1));
		}
		else
			_struggler = num1;
	}
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	(void)copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{}
