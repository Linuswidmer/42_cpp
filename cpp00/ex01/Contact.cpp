#include "Contact.hpp"

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