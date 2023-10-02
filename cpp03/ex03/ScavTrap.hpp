#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
    std::string _name;
    int         _hit_points;
    int         _energy_points;
    int         _attack_damage;

public:
    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& copy);
    virtual ~ScavTrap(void);

    virtual void    attack(const std::string& target);
    void    guardGate(void);

    ScavTrap& operator=(const ScavTrap& other);

private:
    bool    _guard_status;
};
#endif