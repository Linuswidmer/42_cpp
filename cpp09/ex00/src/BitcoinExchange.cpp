#include "BitcoinExchange.hpp"

/*****************************************************************************/
/*                              PUBLIC METHODS                               */
/*****************************************************************************/

/*
*	Reads the input file line by line, converts and prints the result
*/
void	BitcoinExchange::exchange(const char *input) const
{
	std::ifstream inputFile(input);

	if (!inputFile.is_open()) 
		throw(std::runtime_error("Failed to open the input file"));

	std::string content;
	getline(inputFile, content);	// skip first line containing column names

	while(getline(inputFile, content))
	{
		if ( content.empty() )
			continue;

		std::istringstream	inputStream(content);
		std::string			dateStr, amountStr;
		char				separator;

		inputStream >> dateStr >> separator >> amountStr;

		long		date = _dateToInt(dateStr);
		if (date == 0)
			continue;
		double		amount = _amountToFloat(amountStr);
		if (amount == 0)
			continue;
		float		price = _getPriceFromDatabase(date);

		_printExchange(dateStr, amount, price);
	}
}

void	BitcoinExchange::printDataBase(void)
{
	_printMap(_dataBase);
}

/*****************************************************************************/
/*                             PRIVATE METHODS                               */
/*****************************************************************************/

/*
*	Prints the result of the exchange in format: DATE => AMOUNT = VALUE 
*/
void	BitcoinExchange::_printExchange(std::string date, 
											float amount, float price) const
{
	std::cout	<< date << " => "
				<< amount << " = "
				<< amount * price << std::endl;
}

/*
*	Returns the price of the bitcoin on the given date
*/
float	BitcoinExchange::_getPriceFromDatabase(const long &date) const
{
	std::map<long, float>::const_iterator it = _dataBase.lower_bound(date);
	
	if (it == _dataBase.end())
		return (--it)->second;
	else if (it == _dataBase.begin())
		return (it->second);
	else if (it->first == date)
		return (it->second);
	else
		return (--it)->second;
}

/*
*	Reads the database file and stores the data in a map
*/
void	BitcoinExchange::_readDataBase(const char *dataBaseName)
{
	std::ifstream dataBase(dataBaseName);

	if (!dataBase.is_open()) 
		throw(std::runtime_error("Failed to open database file"));

	std::string content;
	getline(dataBase, content);	// skip first line containing column names

	while (getline(dataBase, content))	
		_dataBase[_dateToInt(content.substr(0, 10))] = atof(content.substr(11).c_str());
	dataBase.close();
}

/*
*	Converts a string to a float value
*  - checks if the string is empty
*  - checks if the string is a positive number
*  - checks if the amount is not too large ( > 2147483647 )
*/
float	BitcoinExchange::_amountToFloat(const std::string& amountStr) const
{
	if (amountStr.empty())
	{
		std::cerr << "Error: empty amount\n";
		return (0);
	}
	float amount = atof(amountStr.c_str());

	if (amount < 0 )
	{
		std::cerr << "Error: not a positive number\n";
		return (0);
	}
	if (static_cast<long>(amount) > 1000)
	{
		std::cerr << "Error: too large a number\n";
		return (0);
	}
	return amount;
}

/*
*	Converts a date string to an integer value
*/
int	BitcoinExchange::_dateToInt(const std::string& dateStr) const
{
	// Parse the date components
	std::istringstream dateStream(dateStr);
	int year, month, day;
	char dash1, dash2;
	dateStream >> year >> dash1 >> month >> dash2 >> day;

	if ( !_isDateValid(year, month, day) )
	{
		std::cerr << "Error bad input => " << dateStr << "\n";
		return (0);
	}
    // Combine components into an integer value (YYYYMMDD)
    int result = year * 10000 + month * 100 + day;

    return (result);
}
/*
*	Checks if the date is valid:
*	- year >= 2009 (Bitcoin was created in 2009)
*	- month in [1, 12]
*	- day in [1, 28/30/31] depending on the month

	RETURNS: true if the date is valid, false otherwise
*/
bool	BitcoinExchange::_isDateValid(const int &year, const int &month,	
										const int day) const
{
	if ( year < 2009 )
		return (false);

	if ( month < 1 || month > 12 )
		return (false);

	if ( month == 2 ) // check for month with 28 days
	{
		if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) // leap year condition
		{
			if ( day < 1 || day > 29 )
				return (false);
		}
		else
		{
			if ( day < 1 || day > 28 )
				return (false);
		}
	}
	else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
		month == 10 || month == 12 ) // check for month with 31 days
	{
		if ( day < 1 || day > 31 )
			return (false);
	}
	else // check for month with 30 days
	{
		if ( day < 1 || day > 30 )
			return (false);
	}
	return (true);
}

void	BitcoinExchange::_printMap(std::map<long, float> map) const
{
	for (std::map<long, float>::iterator it = map.begin();
			it != map.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << '\n';
	}
}

/*****************************************************************************/
/*                        DEFAULT CON-/DESTRUCTOR                            */
/*****************************************************************************/


BitcoinExchange::BitcoinExchange(const char *dateBaseName)
{
	_readDataBase(dateBaseName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_dataBase = other._dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}