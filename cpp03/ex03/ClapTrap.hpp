#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>
using namespace std;

class ClapTrap {
private:
    string _name;
    int     _hit_points;
    int     _energy_points;
    int     _attack_damage;

protected:
    //setters
    void name(string name);
    void hit_points(int hp);
    void energy_points(int ep);
    void attack_damage(int ad);

    //getters
    const string  &name(void) const;
    int     hit_points(void) const;
    int     energy_points(void) const;
    int     attack_damage(void) const;

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