#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "CONTRUCTORS" << std::endl;
    ScavTrap s("scavvy");

    std::cout << std::endl << "MEMEBER FUNCTIONS" << std::endl;
    s.stats();
    s.takeDamage(20);
    s.attack("enemy");
    s.guardGate();
    s.stats();

    std::cout << std::endl << "COPY AND ASSIGNEMENT" << std::endl;
    ScavTrap t;
    t = s;
    t.stats();

}