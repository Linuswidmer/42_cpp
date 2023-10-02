#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
    std::string _name;
    int         _hit_points;
    int         _energy_points;
    int         _attack_damage;

public:
    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& copy);
    virtual ~FragTrap(void);

    void    highFiveGuys(void);

    FragTrap& operator=(const FragTrap& other);

private:
};
#endif