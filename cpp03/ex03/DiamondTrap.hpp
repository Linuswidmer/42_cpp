#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap:  public ScavTrap, public FragTrap
{
private:
    std::string  _name;
    int         _hit_points;
    int         _energy_points;
    int         _attack_damage;
    
public:
    DiamondTrap(void);
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& copy);
    ~DiamondTrap(void);

    DiamondTrap& operator=(const DiamondTrap& other);
    void    whoAmI();
    void    attack(const std::string &target);
    void    stats(void) const;
};


#endif