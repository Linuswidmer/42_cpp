#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap c("clappy");
    cout << c << endl;
    ScavTrap s("scavvy");
    cout << s << endl;
    s.takeDamage(20);
    ScavTrap t(s);
    s.attack("enemy");
    s.guardGate();
    cout << s << endl;
}