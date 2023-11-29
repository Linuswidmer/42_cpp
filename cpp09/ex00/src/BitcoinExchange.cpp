#include "BitcoinExchange.hpp"

/*------------------PUBLIC METHODS -----------------*/

/*----------------GETTERS AND SETTERS --------------*/

/*------------------PRIVATE METHODS -----------------*/
void	BitcoinExchange::_readDataBase(void)
{
	std::ifstream dataBase("data.csv");

	if (!dataBase.is_open()) 
		throw(std::runtime_error("Failed to open database file"));

	std::string content;
    getline(dataBase, content);

	std::cout << content << std::endl;

	dataBase.close();
}


/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const char *input_file_name)
{
	(void)input_file_name;
	_readDataBase();
	// std::ifstream inputFile(input_file_name);

    // if (!inputFile.is_open()) 
	// 	throw(std::runtime_error("Failed to open the file"));

	// std::string content;
    // getline(inputFile, content);

	// std::cout << content << std::endl;

	// inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}

/* ----------------OPERATOR OVERLOAD---------------*/