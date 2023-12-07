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

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BABY_BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define RESET_PRINT "\033[0m"

# define DEBUG_FJ 0
# define DEBUG_SORTED 1

class PmergeMe
{
public:
	// public methods
	std::vector<int>	sort();

	//Getters and Setters

	// Constructors, Assignment, Destructors
	PmergeMe(const char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Data
	size_t								_size;

	int									_struggler;
	std::vector<std::pair<int, int> >	_vec;
	std::vector<int>					_mainChain;
	std::vector<int>					_pend;
	std::vector<size_t>					_jacobsthal_sequence;

	// utils
	void	_splitToPendMainChain(void);
	void	_insertToMainChain(int num);
	void	_generateJacobsthalSequence(void);
	void	_printVec(const std::vector<int> &vec) const;

	
};

// _mainChain.insert(_mainChain.begin(), _pend[0]);

#endif