#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d("d");
    //DiamondTrap d_copy(d);
    //ScavTrap    s("scavvy");
    //ScavTrap    s_copy(s);
    //FragTrap    f("fraggy");
    //FragTrap    f_copy(f);

    cout << d;
    d.attack("hello");
    //f.takeDamage(50);
    //f_copy = f;
    //cout << f_copy;

    //s_copy.attack("hello");
    //d.attack("aaaaa");
    //d.whoAmI();
}