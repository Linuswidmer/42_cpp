#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>
using namespace std;

class ClapTrap {
protected:
    string  _name;
    int     _hit_points;
    int     _energy_points;
    int     _attack_damage;

public:
    ClapTrap(const string& name);
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap(void);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void stats(void) const;

    ClapTrap& operator=(const ClapTrap& other);
    friend ostream& operator<<(std::ostream& o, ClapTrap const& rhs);
};
#endif