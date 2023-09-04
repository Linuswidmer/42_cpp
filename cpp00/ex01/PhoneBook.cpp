/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:22:08 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/22 18:23:59 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

std::string formatString(const std::string& input, unsigned long width);

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

int PhoneBook::display_contact(int num)
{
	std::cout	<< "First Name: " << ContactArray[num].get_first_name()		<< std::endl
				<< "Last Name: " << ContactArray[num].get_last_name()			<< std::endl
				<< "Nick Name: " << ContactArray[num].get_nick_name()			<< std::endl
				<< "Phonenumber: " << ContactArray[num].get_phone_number()		<< std::endl
				<< "Darkest Secret: " << ContactArray[num].get_darkest_secret()	<< std::endl
				<< std::endl;
	return (0);
};

void PhoneBook::add_contact(void)
{
	std::string FirstName = "";
	std::string LastName = "";
	std::string NickName = "";
	std::string PhoneNumber = "";
	std::string DarkestSecret = "";

	while (FirstName.empty())
	{
		std::cout << "Enter First Name: ";
		getline(std::cin, FirstName);
	}
	while (LastName.empty())
	{
		std::cout << "Enter Last Name: ";
		getline(std::cin, LastName);
	}
	while (NickName.empty())
	{
		std::cout << "Enter Nick Name: ";
		getline(std::cin, NickName);
	}
	while (PhoneNumber.empty())
	{
		std::cout << "Enter Phone Number: ";
		getline(std::cin, PhoneNumber);
	}
	while (DarkestSecret.empty())
	{
		std::cout << "Enter Darkest Secret: ";
		getline(std::cin, DarkestSecret);
	}
	ContactArray[index % 8] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
	index++;
	return ;
};

int PhoneBook::display_all_contacts(void)
{
	if (index == 0)
	{
		std::cout << "you have no friends:(" << std::endl;
		return (1);
	}
	std::cout << formatString("INDEX", 10) << "|"
              << formatString("FIRST", 10) << "|"
              << formatString("LAST", 10) << "|"
              << formatString("NICK", 10) << "|" << std::endl;

    for (int i = 0; i < index && i < 8; i++) {
        std::cout << "         " <<  i << "|"
                  << formatString(ContactArray[i].get_first_name(), 10) << "|"
                  << formatString(ContactArray[i].get_last_name(), 10) << "|"
                  << formatString(ContactArray[i].get_nick_name(), 10) << "|" << std::endl;
    }
	return (0);
	};

void	PhoneBook::display_prompts(void)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;	
	std::cout << "SEARCH: display a specific conatct" << std::endl;	
	std::cout << "EXIT: !" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}
