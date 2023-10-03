#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "CONTRUCTORS" << std::endl;
    ClapTrap a("trappy");
    ClapTrap b;

    std::cout << std::endl << "MEMEBER FUNCTIONS" << std::endl;
    a.attack("enemy");
    a.takeDamage(5);
    a.stats();
    a.beRepaired(12);
    a.stats();

    std::cout << std::endl << "COPY AND ASSIGNEMENT" << std::endl;
    ClapTrap c(a);

    std::cout << std::endl << "DESTRUCTION" << std::endl;
    return (0);
}