#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string& name, Weapon type)
{
    this->type.setType(weaponType);
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their weapon " << this->type.getType()
            << std::endl;
}