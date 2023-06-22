/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:22:08 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/22 18:16:30 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include <vector>
# include <iomanip>
# include <ctime>
# include <chrono>

class Contact 
{
public:
	int			index;
	//std::time_t	timestamp;
	struct std::tm timestamp;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

std::tm	GetCurrentTimestamp(void)
{
	using std::chrono::system_clock;
  	std::time_t tt = system_clock::to_time_t (system_clock::now());
	std::tm localtime = *std::localtime(&tt);
	return (localtime);
}

bool	CompareTimestamp(const Contact& contact1, const Contact& contact2)
{
	std::time_t time1 = std::mktime(const_cast<std::tm*>(&contact1.timestamp));
	std::time_t time2 = std::mktime(const_cast<std::tm*>(&contact2.timestamp));
	return (time1 < time2);
}

int		GetIndexOfLowestTimestamp(const std::vector<Contact> contacts)
{
	Contact LowestTimestamp;

	LowestTimestamp = contacts[0];
	for (int i = 1; i < contacts.size(); ++i)
	{
		if (CompareTimestamp(contacts[i], LowestTimestamp))
		{
			LowestTimestamp = contacts[i];
		}
	}
	return (LowestTimestamp.index);
}

std::string	adjStringToTen(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	else
		return (str.append(10 - str.length(), ' '));
}

class PhoneBook 
{
public:
	std::vector<Contact> contacts;
	
	void Add(const std::string& str)
	{
		Contact NewContact;

		std::cout << "Enter First Name: ";
		std::cin >> NewContact.FirstName;
		/*
		std::cout << "Enter Last Name: ";
		std::cin >> NewContact.LastName;
		std::cout << "Enter Nick Name: ";
		std::cin >> NewContact.NickName;
		std::cout << "Enter Phone Number: ";
		std::cin >> NewContact.PhoneNumber;
		std::cout << "Enter Darkest Secret: ";
		std::cin >> NewContact.DarkestSecret;
		return ;
		*/
		AddContactToPhoneBook(NewContact);
	};
	void AddContactToPhoneBook(Contact NewContact)
	{
		int	SizeContacts;
		int IndexOldestContact;

		SizeContacts = contacts.size();
		if (SizeContacts <= 2)
		{
			NewContact.index  = SizeContacts;
			NewContact.timestamp = GetCurrentTimestamp();
			contacts.push_back(NewContact);
		}
		else
		{
			IndexOldestContact = GetIndexOfLowestTimestamp(contacts);
			NewContact.index = IndexOldestContact;
			NewContact.timestamp = GetCurrentTimestamp();
			ReplaceContactByIndex(NewContact);
		}
	};
	void Search(const std::string& str)
	{
		DisplayContacts();
	};
	void DisplayContacts(void)
	{
		for (Contact c : contacts)
		{
			std::cout	<< adjStringToTen(std::to_string(c.index))	<< "|"
						<< adjStringToTen(c.FirstName) 				<< "|"
						//<< adjStringToTen(c.LastName) 				<< "|"
						//<< adjStringToTen(c.NickName) 				<< "|"
						<< std::endl;
						//<< std::put_time(const_cast<std::tm*>(&c.timestamp), "%Y-%m-%d %H:%M:%S") 
		}
	};
	void ReplaceContactByIndex(const Contact NewContact)
	{
		int IndexOldestContact;

		IndexOldestContact = NewContact.index;
		contacts[IndexOldestContact] = NewContact;
		return ;
	};
};

#endif

int	display_prompts(void)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;	
	std::cout << "SEARCH: display a specific conatct" << std::endl;	
	std::cout << "EXIT: !" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if (std::cout.fail())
		return (1);
	else
		return (0);
}

int main()
{
	int			exit;
	std::string	input;	
	PhoneBook 	phonebook;

	exit = display_prompts();
	while (1)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cerr << "error occured, exiting program" << std::endl;
			return (1);
		}
		else
		{
			if (input == "ADD")
			{
				phonebook.Add(input);
			}
			else if (input == "SEARCH")
				phonebook.Search(input);
			else if (input == "EXIT")
				break ;
		}
	}
	return (0);
}
