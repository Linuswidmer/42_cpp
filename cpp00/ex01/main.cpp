#include "PhoneBook.hpp"
#include "Contact.hpp"

bool containsOnlyDigits(const std::string& str);
std::string formatString(const std::string& input, unsigned long width);

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
				input_index = atoi(input.c_str());
				if (containsOnlyDigits(input) == false)
					std::cout << "index non numeric" << std::endl;
				else if (input_index >= phonebook.index)
					std::cout << "contact " << input_index << " does not exist" << std::endl;
				else if (input_index < 0 || input_index > 8)
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