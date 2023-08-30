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

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include <iomanip>


std::string	adjStringToTen(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	else
		return (str.append(10 - str.length(), ' '));
}

class Contact 
{
	public:

	// Default constructor for the Contact class
	Contact() :  FirstName(""), LastName(""), NickName(""),
			PhoneNumber(""), DarkestSecret("") {
    }
	Contact(const std::string& FirstName, const std::string& LastName, 
			const std::string& NickName, const std::string& PhoneNumber,
			const std::string& DarkestSecret)
			: FirstName(FirstName), LastName(LastName), NickName(NickName),
			PhoneNumber(PhoneNumber), DarkestSecret(DarkestSecret) {
    };

	//private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
};

// PhoneBook::~PhoneBook()
// {
//     std::cout << "PhoneBook destructor called!" << std::endl;
// }


class PhoneBook 
{
	// Default constructor
	public:
		PhoneBook(){
			this->index = 0;
		}
		int 		index;
		Contact		ContactArray[8];
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;	

	void Add(void)
	{
		// use getline here
		// no empty line allowed
		std::cout << "Enter First Name: ";
		std::cin >> FirstName;
		std::cout << "Enter Last Name: ";
		std::cin >> LastName;
		std::cout << "Enter Nick Name: ";
		std::cin >> NickName;
		std::cout << "Enter Phone Number: ";
		std::cin >> PhoneNumber;
		std::cout << "Enter Darkest Secret: ";
		std::cin >> DarkestSecret;
		ContactArray[index % 8] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
		index++;
		return ;
	};

	void Search(void)
	{
		DisplayAllContacts();
	};

	void DisplayAllContacts(void)
	{
		for (int i = 0; i < index && i < 8; i++)
		{
			std::cout	<< i << "         "								<< "|"
						<< adjStringToTen(ContactArray[i].FirstName) 	<< "|"
						<< adjStringToTen(ContactArray[i].LastName) 	<< "|"
						<< adjStringToTen(ContactArray[i].NickName) 	<< "|"
						<< std::endl;
		}
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
	int						exit;
	std::string				input;	
	PhoneBook 				phonebook;

	exit = display_prompts();
	while (1)
	{
		std::cin >> input;
		if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
		{
			phonebook.Search();
			// Prompt for one specific contact
		}
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
