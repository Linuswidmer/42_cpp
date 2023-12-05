# include "RPN.hpp"

int	main(int argc, char **argv)
{
	if ( argc == 2 )
	{
		RPN		rpn;
		float	result;

		if ( rpn.calculate(std::string(argv[1]), &result) )
			std::cout << "Result is " << result << std::endl;
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <rpn> " << std::endl;
		return (1);
	}
}