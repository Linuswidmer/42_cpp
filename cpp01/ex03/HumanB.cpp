#include "HumanB.hpp"

HumanB::HumanB(const char *name)
{
    this->_name = name;
    this->_type = NULL;
}

void    HumanB::attack(void)
{
    if (this->_type)
    {
        std::cout << this->_name << " attacks with their weapon " << (*(this->_type)).getType()
             << std::endl;
    }
    else
        std::cout << this->_name << " attacks with their bare hands" << std::endl;
}

void    HumanB::setWeapon(Weapon &newWeapon)
{
    this->_type = &newWeapon;
}