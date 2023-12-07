#include "PmergeMe.hpp"

/*****************************************************************************/
/*                              PUBLIC METHODS                               */
/*****************************************************************************/

//TODO
// 1. check input in the constructor
// 4. recurisiveness ???
// 5. make a template class	out of PmergeMe

std::vector<int>	PmergeMe::vecSort()
{
	_sortPairsByLargest(_vec);

	_splitToPendMainChain(_vecMainChain, _vecPend);

	_insertionByJacobsthalSequence(_vecMainChain, _vecPend);

	_insertStruggler(_vecMainChain);

	return (_vecMainChain);
}

std::deque<int>	PmergeMe::dequeSort()
{
	_sortPairsByLargest(_deque);

	_splitToPendMainChain(_dequeMainChain, _dequePend);

	_insertionByJacobsthalSequence(_dequeMainChain, _dequePend);

	_insertStruggler(_dequeMainChain);

	return (_dequeMainChain);
}

/*****************************************************************************/
/*                             PRIVATE METHODS                               */
/*****************************************************************************/

template <typename T>
void	PmergeMe::_sortPairsByLargest(T &vec)
{
	std::sort(vec.begin(), vec.end());
	if (DEBUG_FJ)
	{
		std::cout	<<  YELLOW << "STEP 3: sort larger elements from each pair" 
					<< RESET_PRINT << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << "(" << vec[i].first << ", " << vec[i].second << ") \n";
		}
	}
}

template <typename T>
void	PmergeMe::_splitToPendMainChain(T &mainChain, T &pend)
{
	if (DEBUG_FJ)
	{
		std::cout	<<  YELLOW << "\nSTEP 4: Create the main chain and the pend"
					<< RESET_PRINT << std::endl;
	}
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (i == 0)
		{
			pend.push_back(_vec[i].second);
			mainChain.push_back(_vec[i].first);
		}
		else
		{
			mainChain.push_back(_vec[i].first);
			pend.push_back(_vec[i].second);
		}
	}

		if (DEBUG_FJ)
	{
		std::cout << "\tMain chain: ";
		_printVec(_vecMainChain);
		std::cout << "\tPend: ";
		_printVec(_vecPend);
	}
}

template <typename T>
void	PmergeMe::_insertionByJacobsthalSequence(T &mainChain, T &pend)
{
	if (DEBUG_FJ)
	std::cout	<< YELLOW << "\nSTEP 5: Create the jacobsthal sequence and insert" 
				<<"  the pend into the main chain" <<  RESET_PRINT << std::endl;

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
}

template <typename T>
void	PmergeMe::_insertStruggler(T &mainChain)
{
	if (_struggler != -1)
	{
		if (DEBUG_FJ)
			std::cout << YELLOW << "\nSTEP 6: Insert the struggler: " << RESET_PRINT << _struggler << std::endl;
		_insertToMainChain(_struggler, mainChain);
	}
}

/*
*	Binary insertion algorithm that inserts a number into the main chain
*/
template <typename T>
void	PmergeMe::_insertToMainChain(int num, T &mainChain)
{
	int left = 0;
	int right = mainChain.size();

	while ( left < right ) 
	{
		int mid = left + (right - left) / 2;
		if (num < mainChain[mid])
			right = mid;
		else
			left = mid + 1;
	}
	mainChain.insert(mainChain.begin() + left, num);
}

void	PmergeMe::_generateJacobsthalSequence(void)
{
	_jacobsthal_sequence.push_back(0);
    _jacobsthal_sequence.push_back(1);

    for (int i = 2; i < 20; ++i) {
        _jacobsthal_sequence.push_back(_jacobsthal_sequence[i - 1] + 2 * _jacobsthal_sequence[i - 2]);
    }
}

template <typename T>
void	PmergeMe::_printVec(const T &vec) const
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

/*****************************************************************************/
/*                        DEFAULT CON-/DESTRUCTOR                            */
/*****************************************************************************/

PmergeMe::PmergeMe(const char **argv)
	: _size(0), _struggler(-1)
{

	// check if input is valid, if all numbers are positive etc
	// check that there is at least two numbers (or three?)

	_generateJacobsthalSequence();
	// check input?

	for (int i = 0; argv[i] != NULL; i = i + 2)
	{
		if (argv[i + 1] != NULL)
		{
			if (atoi(argv[i]) >= atoi(argv[i + 1]))
			{
				_vec.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
				_deque.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
			}
			else
			{
				_vec.push_back(std::make_pair(atoi(argv[i + 1]), atoi(argv[i])));
				_deque.push_back(std::make_pair(atoi(argv[i + 1]), atoi(argv[i]))); 
			}
			_size = _size + 2;
		}
		else
		{
			_struggler = atoi(argv[i]);
			break;
		}
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
