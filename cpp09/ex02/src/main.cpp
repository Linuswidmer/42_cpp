# include "PmergeMe.hpp"

// ./PmergeMe 7 8 27 100 11 46 2 53 0 
// ./PmergeMe `shuf -i 1-100000 -n 100 | tr "\n" " "`

template <typename T>
bool isSorted(const char **argv, T sorted_vector)
{
	T copy;
	for (int i = 1; argv[i]; i++) 
		copy.push_back(std::atoi(argv[i]));

	std::sort(copy.begin(), copy.end());
	
	if (sorted_vector == copy)
			std::cout << GREEN << "\tContainer is sorted!" << RESET_PRINT << std::endl;
		else
		{
			std::cout << RED << "\tContainter is not sorted!" << RESET_PRINT << std::endl;
			std::cout << "Copy vector: ";
			for (size_t i = 0; i < copy.size(); i++)
				std::cout << copy[i] << " ";
			std::cout << std::endl;
		}

	return (sorted_vector == copy);
}

int	main(int argc, const char **argv)
{
	if ( argc > 1 )
	{
		PmergeMe			fj_vector( argv + 1);
		std::vector<int>	sorted_vector;
		std::deque<int>		sorted_deque;
		clock_t				start, end;

		/////////////////////////////////////////////////////////////////////
		// Vector
		start = clock();
		sorted_vector = fj_vector.vecSort();
		end = clock();
		std::cout	<< "Time to process a range of " << argc - 1 << " elements: " 
					<< static_cast<double>(end - start) / CLOCKS_PER_SEC
					<< " microseconds" << std::endl;
		if (DEBUG_SORTED)
			isSorted(argv, sorted_vector);
		
		/////////////////////////////////////////////////////////////////////
		// Deque
		start = clock();
		sorted_deque = fj_vector.dequeSort();
		end = clock();
		std::cout	<< "Time to process a range of " << argc - 1 << " elements: " 
					<< static_cast<double>(end - start) / CLOCKS_PER_SEC
					<< " microseconds" << std::endl;
		if (DEBUG_SORTED)
			isSorted(argv, sorted_deque);

		std::cout << "\nBefore: ";
		for (int i = 1; argv[i] && i < 5; i++) 
			std::cout << argv[i] << " ";
		if (argc > 5)
			std::cout << "...";
		std::cout << std::endl;

		std::cout << "After: ";
		for (size_t i = 0; i < sorted_vector.size() && i < 5; i++)
			std::cout << sorted_vector[i] << " ";
		if (sorted_vector.size() > 5)
			std::cout << "...";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <number to sort> " << std::endl;
		return (1);
	}
}