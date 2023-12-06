# include "PmergeMe.hpp"

// ./PmergeMe "7 8 27 100 11 46 2 53 0"

int	main(int argc, char **argv)
{
	if ( argc == 2 )
	{
		PmergeMe			fj_vector( (std::string(argv[1])) );

		fj_vector.sort();
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <number to sort> " << std::endl;
		return (1);
	}
}