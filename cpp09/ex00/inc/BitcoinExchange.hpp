#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <stdlib.h>
# include <algorithm>

class BitcoinExchange
{
public:
	// public methods
	void	exchange(const char *input) const;
	void	printDataBase(void); 

	// Constructors, Assignment, Destructors
	BitcoinExchange(const char *input_file_name);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange(void);

private:
	BitcoinExchange(void);

	void	_readDataBase(const char *dataBaseName);
	float	_getPriceFromDatabase(const long &date) const;
	void	_printExchange(std::string date, float amount, float price) const;

	// Data
	std::map<long, float> _dataBase;

	// utils
	void	_printMap(std::map<long, float> map) const;
	int		_dateToInt(const std::string &date) const;
	float	_amountToFloat(const std::string &amount) const;
	bool 	_isDateValid(const int &year, const int &month, const int day) const;
};

#endif