#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
public:
	// public methods

	//Getters and Setters

	// Constructors, Assignment, Destructors
	BitcoinExchange(const char *input_file_name);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange(void);

private:
	BitcoinExchange(void);

	void	_readDataBase(void);

	// Data
};

#endif