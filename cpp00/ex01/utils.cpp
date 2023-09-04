#include "PhoneBook.hpp"

bool containsOnlyDigits(const std::string& str) 
{
    for (unsigned long i = 0; i < str.size(); i++) 
	{
        if (!std::isdigit(str[i])) 
		{
            return (false);
        }
    }
    return (true);
}

std::string formatString(const std::string& input, unsigned long width) 
{
	if (input.length() > width) 
	{
		return input.substr(0, width - 1) + ".";
	} 
	else 
	{
		return std::string(width - input.length(), ' ') + input;
	}
}
