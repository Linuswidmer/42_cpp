#include "HumanB.hpp"

HumanB::HumanB()
{}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their weapon " << this->type.getType()
            << std::endl;
}