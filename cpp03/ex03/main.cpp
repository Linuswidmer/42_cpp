#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "CONTRUCTORS" << std::endl;
    DiamondTrap d("d");

    std::cout << std::endl << "MEMEBER FUNCTIONS" << std::endl;
    d.stats();
    d.attack("hello");
    d.whoAmI();

    std::cout << std::endl << "COPY AND ASSIGNEMENT" << std::endl;
    DiamondTrap d_copy(d);
    d.stats();
    // d_copy = d;
       
    std::cout << std::endl << "DESTRUCTION" << std::endl;
}