#include "ClapTrap.hpp"
#include "FlagTrap.hpp"

int main(void)
{
    ClapTrap c("clappy");
    cout << c << endl;
    FlagTrap f("flaggy");
    cout << f << endl;
    f.takeDamage(20);
    FlagTrap t(f);
    f.attack("enemy");
    f.highFiveGuys();
    cout << f << endl;
}