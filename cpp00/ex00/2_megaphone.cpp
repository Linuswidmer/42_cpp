/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_megaphone.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:35 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/07 11:11:37 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_H
# define MEGAPHONE_H

# include <iostream>

class Megaphone {

private:
	std::string UppercaseString;

public:
	Megaphone(const std::string& str)
	{
		UppercaseString = ConvertToUppercase(str);
	}
	std::string GetUppercaseString() const 
	{
		return (UppercaseString);
	}
private:
	std::string ConvertToUppercase(const std::string& str) 
	{
    	std::string result;
    	result.reserve(str.length());

    	for (char c : str)
    	{
        	result.push_back(std::toupper(c));
    	}
    	return result;
	}
};
#endif

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1;  i < argc; ++i)
		{
			Megaphone megaphone(argv[i]);
			std::cout << megaphone.GetUppercaseString();
		}
		std::cout << std::endl;
	}
}
