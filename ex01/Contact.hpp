#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact 
{
	public:
	// Default constructor for the Contact class
	Contact() :  _FirstName(""), _LastName(""), _NickName(""),
			_PhoneNumber(""), _DarkestSecret("") {
    }
	// To add a new contact
	Contact(const std::string& FirstName, const std::string& LastName, 
			const std::string& NickName, const std::string& PhoneNumber,
			const std::string& DarkestSecret)
			: _FirstName(FirstName), _LastName(LastName), _NickName(NickName),
			_PhoneNumber(PhoneNumber), _DarkestSecret(DarkestSecret) {
    };

	std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nick_name() const;
    std::string get_darkest_secret() const;
    std::string get_phone_number() const;

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};
#endif