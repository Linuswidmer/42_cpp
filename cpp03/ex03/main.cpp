#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d("d");
    //DiamondTrap d_copy(d);
    // ScavTrap    s("scavvy");
    //ScavTrap    s_copy(s);
    //FragTrap    f("fraggy");
    //FragTrap    f_copy(f);

    cout << d;
    d.beRepaired(20);
    cout << d;
    //cout << d;
    //d.attack("hello");
    //cout << f;
    //f.takeDamage(50);
    //cout << f;
    //f_copy = f;
    //cout << f_copy;

    //cout << d;
    //s_copy.attack("hello");
    //d.attack("aaaaa");
    //d.whoAmI();
}