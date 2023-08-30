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

std::string	adjStringToTen(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str.append(10 - str.length(), ' '));
}

int PhoneBook::display_contact(int num)
	{
		if (index < 8 && num >= index)
		{
			std::cout << "invalid index" << std::endl;
			return (1);
		}
		for (int i = 0; i < index && i < 8; i++)
		{
			std::cout	<< "First Name: " << ContactArray[i].get_first_name()		<< std::endl
						<< "Last Name: " << ContactArray[i].get_last_name()			<< std::endl
						<< "Nick Name: " << ContactArray[i].get_nick_name()			<< std::endl
						<< "Phonenumber: " << ContactArray[i].get_phone_number()		<< std::endl
						<< "Darkest Secret: " << ContactArray[i].get_darkest_secret()	<< std::endl
						<< std::endl;
		}
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
		// working with setters instead??
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
		for (int i = 0; i < index && i < 8; i++)
		{
			std::cout	<< adjStringToTen("INDEX")	<< "|"
						<< adjStringToTen("FIRST NAME") 	<< "|"
						<< adjStringToTen("LAST NAME") 	<< "|"
						<< adjStringToTen("NICKNAME") 	<< "|"
						<< std::endl;
			std::cout	<< i << "         "								<< "|"
						<< adjStringToTen(ContactArray[i].get_first_name()) 	<< "|"
						<< adjStringToTen(ContactArray[i].get_last_name()) 	<< "|"
						<< adjStringToTen(ContactArray[i].get_nick_name()) 	<< "|"
						<< std::endl;
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

int main()
{
	int						input_index;
	std::string				input;	
	PhoneBook 				phonebook;

	phonebook.display_prompts();
	while (1)
	{
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
		{
			if (!phonebook.display_all_contacts())
			{
				std::cout << "Type index to display complete entry ";
				std::getline(std::cin, input);
				// this is not 100% correct, i would need to check digits or do something elese
				input_index = atoi(input.c_str());
				if (input_index < 0 || input_index > 8)
					std::cout << "index out of bound, type number between 0 and 7" << std::endl;
				else
					phonebook.display_contact(input_index);
			}
		}
		else if (input == "EXIT")
			break ;
		std::cout << std::endl;
	}
	return (0);
}
