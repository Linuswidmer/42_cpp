# include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange bex("data.csv");
			bex.exchange(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		std::cerr << "Error, incorrect usage \n ./btc <input_file>\n";
	}
}