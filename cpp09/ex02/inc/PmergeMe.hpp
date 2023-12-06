#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <sstream>
# include <utility>

class PmergeMe
{
public:
	// public methods
	void	sort();

	//Getters and Setters

	// Constructors, Assignment, Destructors
	PmergeMe(const std::string &numStr);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Data
	int									_struggler;
	std::vector<std::pair<int, int> >	_vec;
	std::vector<int>					_mainChain;
	std::vector<int>					_pend;

	
};

#endif