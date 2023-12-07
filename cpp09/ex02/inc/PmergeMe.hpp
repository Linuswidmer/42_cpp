#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <sstream>
# include <utility>
# include <stdlib.h>
# include <math.h>
# include <ctime>
# include <deque>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BABY_BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define RESET_PRINT "\033[0m"

# define DEBUG_FJ 0
# define DEBUG_SORTED 1

// template <typename Container>
class PmergeMe
{
public:
	// public methods
	std::vector<int>	vecSort();
	std::deque<int>		dequeSort();

	// Constructors, Assignment, Destructors
	PmergeMe(const char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Sorting methods
	template <typename T>
	void	_sortPairsByLargest(T &vec);
	template <typename T>
	void	_splitToPendMainChain(T &mainChain, T &pend);
	template <typename T>
	void	_insertionByJacobsthalSequence(T &mainChain, T &pend);
	template <typename T>
	void	_insertStruggler(T &mainChain);

	// General data
	std::vector<size_t>					_jacobsthal_sequence;
	size_t								_size;
	int									_struggler;
	
	// Vector data
	std::vector<std::pair<int, int> >	_vec;
	std::vector<int>					_vecMainChain;
	std::vector<int>					_vecPend;


	// List data
	std::deque<std::pair<int, int> >	_deque;
	std::deque<int>						_dequeMainChain;
	std::deque<int>						_dequePend;

	// utils
	template <typename T>
	void	_insertToMainChain(int num, T &mainChain);
	template <typename T>
	void	_printVec(const T &vec) const;
	void	_generateJacobsthalSequence(void);
};

/* void	PmergeMe::_insertionByJacobsthalSequence(std::vector<int> &mainChain, std::vector<int> &pend)
{
	if (DEBUG_FJ)
	std::cout	<< YELLOW << "\nSTEP 5: Create the jacobsthal sequence and insert the pend" 
				<<" into the main chain" <<  RESET_PRINT << std::endl;

	// insert the first element of the pend to the beginning of the main chain
	mainChain.insert(mainChain.begin(), pend[0]);



	bool finished = false;
	for (size_t jacobsthal_index = 3; finished == false; jacobsthal_index++)
	{
		size_t index_to_sort = _jacobsthal_sequence[jacobsthal_index];
		while ( index_to_sort > _jacobsthal_sequence[jacobsthal_index - 1] )
		{
			if ( index_to_sort <= pend.size())
			{
				_insertToMainChain(pend[index_to_sort - 1], mainChain);
			}
			index_to_sort = index_to_sort - 1;
			if (mainChain.size() == _size)
			{
				finished = true;
				break;
			}
		}
	}
} */

#endif