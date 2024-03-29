#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <iomanip>

class PhoneBook 
{

public:
	int 		index;	
	PhoneBook(void);

	void	display_prompts();
	void	add_contact();
	int		display_all_contacts();
	int		display_contact(int num);

private:
    Contact		ContactArray[8];
};

#endif
