#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("trappy");
    ClapTrap b(a);

    a.attack("enemy");
    a.takeDamage(5);
    cout << a;
    a.beRepaired(12);
    cout << a;
    return (0);
}