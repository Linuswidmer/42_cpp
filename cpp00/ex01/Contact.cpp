#include "Contact.hpp"

Contact::Contact() :  _FirstName(""), _LastName(""), _NickName(""),
			_PhoneNumber(""), _DarkestSecret("") 
{};

Contact::Contact(const std::string& FirstName, const std::string& LastName, 
			    const std::string& NickName, const std::string& PhoneNumber,
			    const std::string& DarkestSecret)
			    : _FirstName(FirstName), _LastName(LastName), _NickName(NickName),
		    	_PhoneNumber(PhoneNumber), _DarkestSecret(DarkestSecret) 
{};

std::string Contact::get_first_name() const
{
    return (this->_FirstName);
}

std::string Contact::get_last_name() const
{
    return (this->_LastName);
}

std::string Contact::get_nick_name() const
{
    return (this->_NickName);
}

std::string Contact::get_phone_number() const
{
    return (this->_PhoneNumber);
}

std::string Contact::get_darkest_secret() const
{
    return (this->_DarkestSecret);
}
