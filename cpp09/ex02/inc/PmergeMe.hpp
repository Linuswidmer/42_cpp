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
# include <cctype>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BABY_BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define RESET_PRINT "\033[0m"

# define DEBUG_FJ 0
# define IS_SORTED 0	
# define COMPARE_STD_SORT 0

template <typename C, typename CPair>
class PmergeMe
{
public:
	// public methods
	C	sort();

	// Constructors, Assignment, Destructors
	PmergeMe(const char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Container
	CPair	_con;
	C		_conMainChain;
	C		_conPend;

	// General
	C		_jacobsthal_sequence;
	size_t	_size;
	int		_struggler;
	
	// Sorting methods
	void	_sortPairsByLargest(CPair &con);
	void	_splitToPendMainChain(C &mainChain, C &pend);
	void	_insertionByJacobsthalSequence(C &mainChain, C &pend);
	void	_insertStruggler(C &mainChain);
	
	// utils
	void	_insertToMainChain(int num, C &mainChain);
	void	_print(const C &con) const;
	void	_generateJacobsthalSequence(void);
	void	_checkInput(const char **argv);
	bool	_isNumeric(const char *str);
	void	_quickSort(CPair &con, int left, int right);
	int		_partition(CPair &con, int left, int right);
};

#include "PmergeMe.tpp"

#endif