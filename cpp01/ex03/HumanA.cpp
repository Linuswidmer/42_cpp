#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _type(weapon)
{
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their weapon " << this->_type.getType()
            << std::endl;
}