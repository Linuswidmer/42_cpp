// orthodox canonical form!
#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>
using namespace std;

class ClapTrap {
private:
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

    //getters
    std::string name(void) const;
    int hit_points(void) const;
    int energy_points(void) const;
    int attack_damage(void) const;

    ClapTrap& operator=(const ClapTrap& other);
};

ostream& operator<<(std::ostream& o, ClapTrap const& rhs);
#endif