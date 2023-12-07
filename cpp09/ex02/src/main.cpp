# include "PmergeMe.hpp"

// ./PmergeMe 7 8 27 100 11 46 2 53 0 
// ./PmergeMe `shuf -i 1-100000 -n 100 | tr "\n" " "`

bool isSorted(const char **argv, const std::vector<int> sorted_vector)
{
	std::vector<int> copy;
	for (int i = 1; argv[i]; i++) 
		copy.push_back(std::atoi(argv[i]));

	std::sort(copy.begin(), copy.end());
	
	if (sorted_vector == copy)
			std::cout << "\033[1;32m" << "\n\tVector is sorted!" << "\033[0m" << std::endl;
		else
		{
			std::cout << "\033[1;31m" << "\n\tVector is not sorted!" << "\033[0m" << std::endl;
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

		std::cout << "Before: ";
		for (int i = 1; argv[i] && i < 5; i++) 
			std::cout << argv[i] << " ";
		if (argc > 5)
			std::cout << "...";
		std::cout << std::endl;

		clock_t start = clock();
		sorted_vector = fj_vector.sort();
		clock_t end = clock();

		std::cout << "After: ";
		for (size_t i = 0; i < sorted_vector.size() && i < 5; i++)
			std::cout << sorted_vector[i] << " ";
		if (sorted_vector.size() > 5)
			std::cout << "...";
		std::cout << std::endl;

		std::cout	<< "Time to process a range of " << argc - 1 << " elements: " 
					<< static_cast<double>(end - start) / CLOCKS_PER_SEC
					<< " microseconds" << std::endl;

		if (DEBUG_SORTED)
			isSorted(argv, sorted_vector);
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <number to sort> " << std::endl;
		return (1);
	}
}