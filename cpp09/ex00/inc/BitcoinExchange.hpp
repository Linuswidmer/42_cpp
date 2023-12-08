#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <stdlib.h>
# include <algorithm>
# include <cstdlib>

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

	// Data
	std::map<long, double> _dataBase;

	void	_readDataBase(const char *dataBaseName);
	double	_getPriceFromDatabase(const long &date) const;
	void	_printExchange(std::string date, double amount, double price) const;

	// utils
	void	_printMap(std::map<long, double> map) const;
	int		_dateToInt(const std::string &date) const;
	double	_amountToDouble(const std::string &amount) const;
	bool 	_isDateValid(const int &year, const int &month, const int day) const;
};

#endif