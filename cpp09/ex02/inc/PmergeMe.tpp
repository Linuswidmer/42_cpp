#include "PmergeMe.hpp"

/*****************************************************************************/
/*                              PUBLIC METHODS                               */
/*****************************************************************************/

/*
*	Uses the Ford-Johnson algorithm to sort the Container. STEPS:
*	1. Sort the pairs by the largest element
*	2. Split the pairs into the main chain and the pend
*	3. Create the jacobsthal sequence and insert the pend into the main chain
*	4. Insert the struggler
*	RETURN: the sorted cotainer
*/
template <typename C, typename CPair>
C	PmergeMe<C, CPair>::sort()
{
	_sortPairsByLargest(_con);

	_splitToPendMainChain(_conMainChain, _conPend);

	_insertionByJacobsthalSequence(_conMainChain, _conPend);

	_insertStruggler(_conMainChain);

	return (_conMainChain);
}

/*****************************************************************************/
/*                             PRIVATE METHODS                               */
/*****************************************************************************/

/*
*	Uses a recursive quicksort algorithm to sort the pairs by the largest
*/
template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_sortPairsByLargest(CPair &con)
{
	_quickSort(con, 0, con.size() - 1);
	if (DEBUG_FJ)
	{
		std::cout	<<  YELLOW << "STEP 1: sort larger elements from each pair" 
					<< RESET_PRINT << std::endl;
		for (size_t i = 0; i < con.size(); i++)
		{
			std::cout << "(" << con[i].first << ", " << con[i].second << ") \n";
		}
	}
}

template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_splitToPendMainChain(C &mainChain, C &pend)
{
	if (DEBUG_FJ)
	{
		std::cout	<<  YELLOW << "\nSTEP 2: Create the main chain and the pend"
					<< RESET_PRINT << std::endl;
	}
	for (size_t i = 0; i < _con.size(); i++)
	{
		if (i == 0)
		{
			pend.push_back(_con[i].second);
			mainChain.push_back(_con[i].first);
		}
		else
		{
			mainChain.push_back(_con[i].first);
			pend.push_back(_con[i].second);
		}
	}
	if (DEBUG_FJ)
	{
		std::cout << "\tMain chain: ";
		_print(_conMainChain);
		std::cout << "\tPend: ";
		_print(_conPend);
	}
}

/*
*	Computes which index of the pend should be inserted into the main chain
*	by decrementinf the jacobstahl number until it reaches the previous
*	jacobstahl number. Inserts this number using binary insertion algorithm
*/
template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_insertionByJacobsthalSequence(C &mainChain, C &pend)
{
	if (DEBUG_FJ)
	std::cout	<< YELLOW << "\nSTEP 3: Create the jacobsthal sequence and insert" 
				<<"  the pend into the main chain" <<  RESET_PRINT << std::endl;

	// insert the first element of the pend to the beginning of the main chain
	mainChain.insert(mainChain.begin(), pend[0]);

	bool finished = false;
	for (int jacobsthal_index = 3; finished == false; jacobsthal_index++)
	{
		int index_to_sort = _jacobsthal_sequence[jacobsthal_index];
		while ( index_to_sort > _jacobsthal_sequence[jacobsthal_index - 1] )
		{
			if ( index_to_sort <= static_cast<int>(pend.size()))
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

template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_insertStruggler(C &mainChain)
{
	if (_struggler != -1)
	{
		if (DEBUG_FJ)
			std::cout << YELLOW << "\nSTEP 4: Insert the struggler: " << RESET_PRINT << _struggler << std::endl;
		_insertToMainChain(_struggler, mainChain);
	}
}

/*
*	Binary insertion algorithm that inserts a number into the main chain
*/
template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_insertToMainChain(int num, C &mainChain)
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

template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_generateJacobsthalSequence(void)
{
	_jacobsthal_sequence.push_back(0);
    _jacobsthal_sequence.push_back(1);

    for (int i = 2; i < 20; ++i) {
        _jacobsthal_sequence.push_back(_jacobsthal_sequence[i - 1] + 2 * _jacobsthal_sequence[i - 2]);
    }
}

template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_checkInput(const char **argv)
{

	int i = 0;
	for (; argv[i]; i++)
	{
		if (!_isNumeric(argv[i]))
			throw(std::invalid_argument("Invalid input: not a number"));
	}
	if (i < 2)
		throw(std::invalid_argument("Invalid input: not enough numbers"));

}

template <typename C, typename CPair>
void PmergeMe<C, CPair>::_quickSort(CPair &con, int low, int high)
{
    if (low < high)
    {
        int pi = _partition(con, low, high);
        _quickSort(con, low, pi - 1);
        _quickSort(con, pi + 1, high);
    }
}

template <typename C, typename CPair>
int PmergeMe<C, CPair>::_partition(CPair &con, int low, int high)
{
    std::pair<int, int> pivot = con[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (std::max(con[j].first, con[j].second) <= std::max(pivot.first, pivot.second))
        {
            i++;
            std::swap(con[i], con[j]);
        }
    }
    std::swap(con[i + 1], con[high]);
    return (i + 1);
}

template <typename C, typename CPair>
bool	PmergeMe<C, CPair>::_isNumeric(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

template <typename C, typename CPair>
void	PmergeMe<C, CPair>::_print(const C &con) const
{
	for (size_t i = 0; i < con.size(); i++)
		std::cout << con[i] << " ";
	std::cout << std::endl;
}

/*****************************************************************************/
/*                        DEFAULT CON-/DESTRUCTOR                            */
/*****************************************************************************/

template <typename C, typename CPair>
PmergeMe<C, CPair>::PmergeMe(const char **argv)
	: _size(0), _struggler(-1)
{
	_checkInput(argv);
	_generateJacobsthalSequence();

	for (int i = 0; argv[i] != NULL; i = i + 2)
	{
		if (argv[i + 1] != NULL)
		{
			if (atoi(argv[i]) >= atoi(argv[i + 1]))
				_con.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
			else
				_con.push_back(std::make_pair(atoi(argv[i + 1]), atoi(argv[i])));
			_size = _size + 2;
		}
		else
		{
			_struggler = atoi(argv[i]);
			break;
		}
	}
}

template <typename C, typename CPair>
PmergeMe<C, CPair>::PmergeMe(const PmergeMe& copy)
{
	this = copy;
}

template <typename C, typename CPair>
PmergeMe<C, CPair>& PmergeMe<C, CPair>::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_con = other._con;
		_conMainChain = other._conMainChain;
		_conPend = other._conPend;
		_jacobsthal_sequence = other._jacobsthal_sequence;
		_size = other._size;
		_struggler = other._struggler;
	}
	return (*this);
}

template <typename C, typename CPair>
PmergeMe<C, CPair>::~PmergeMe(void)
{}