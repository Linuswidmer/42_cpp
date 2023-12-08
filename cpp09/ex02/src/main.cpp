# include "PmergeMe.hpp"

// arguments for the program
	// ./PmergeMe 7 8 27 100 11 46 2 53 0 
	// ./PmergeMe `shuf -i 1-100000 -n 100 | tr "\n" " "`

// why is the deque slower than the vector?
	// As opposed to std::vector, the elements of a deque are not stored 
	// contiguously: typical implementations use a sequence of individually 
	// allocated fixed-size arrays, with additional bookkeeping, which means 
	// indexed access to deque must perform two pointer dereferences, 
	// compared to vector's indexed access which performs only one.
// from	https://en.cppreference.com/w/cpp/container/deque

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

void	printElements(int argc, const char **argv, std::vector<int> sorted_vector)
{
	std::cout << "\nBefore: ";
	for (int i = 1; argv[i] && i <= 5; i++) 
		std::cout << argv[i] << " ";
	if (argc > 6)
		std::cout << "...";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < sorted_vector.size() && i < 5; i++)
		std::cout << sorted_vector[i] << " ";
	if (sorted_vector.size() > 5)
		std::cout << "...";
	std::cout << std::endl;
}

template <typename C>
void	printContainer(const C &con)
{
	for (size_t i = 0; i < con.size(); i++)
		std::cout << con[i] << " ";
	std::cout << std::endl;
}

int	main(int argc, const char **argv)
{
	if ( argc > 1 )
	{
		std::vector<int>	sorted_vector;
		std::deque<int>		sorted_deque;
		try
		{
			/////////////////////////////////////////////////////////////////////
			// Vector
			PmergeMe<std::vector<int>, 
				std::vector<std::pair<int, int> > >	fj_vector( argv + 1);
			sorted_vector = fj_vector.sort();
			std::cout	<< "Time to process a range of " << argc - 1 << " elements" 
						<< " with vector: " << MAGENTA << fj_vector.getTime() 
						<<  RESET_PRINT << " seconds" << std::endl;
			if (IS_SORTED)
				isSorted(argv, sorted_vector);
			if (PRINT_SORTED)
				printContainer(sorted_vector);
			
			/////////////////////////////////////////////////////////////////////
			// Deque
			PmergeMe<std::deque<int>, 
				std::deque<std::pair<int, int> > >	fj_deque( argv + 1);
			sorted_deque = fj_deque.sort();
			std::cout	<< "Time to process a range of " << argc - 1 << " elements" 
						<< " with deque: " << MAGENTA << fj_deque.getTime() 
						<< RESET_PRINT << " seconds" << std::endl;
			
			if (IS_SORTED)
				isSorted(argv, sorted_deque);
			if (PRINT_SORTED)
				printContainer(sorted_vector);

			printElements(argc, argv, sorted_vector);

			/////////////////////////////////////////////////////////////////////
			// std::sort
			if (COMPARE_STD_SORT)
			{
				clock_t				start, end;
				std::vector<int>	vec;
				for (int i = 1; argv[i]; i++) 
					vec.push_back(std::atoi(argv[i]));
				start = clock();
				std::sort(vec.begin(), vec.end());
				end = clock();
				std::cout	<< "Time to process a range of " << argc - 1 << " elements with vector + std::sort: " 
							<< MAGENTA << static_cast<double>(end - start) / CLOCKS_PER_SEC
							<< RESET_PRINT << " seconds" << std::endl;
				if (IS_SORTED)
					isSorted(argv, vec);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}

	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <num1> <num2> <...>" << std::endl;
		return (1);
	}
}