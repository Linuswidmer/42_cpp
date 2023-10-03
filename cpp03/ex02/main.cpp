#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "CONTRUCTORS" << std::endl;
    FragTrap f("flaggy");

    std::cout << std::endl << "MEMEBER FUNCTIONS" << std::endl;
    f.takeDamage(20);
    f.attack("enemy");
    f.highFiveGuys();
    f.stats();


    std::cout << std::endl << "COPY AND ASSIGNEMENT" << std::endl;
    FragTrap t(f);
    t.stats();

    std::cout << std::endl << "DESTRUCTION" << std::endl;
}