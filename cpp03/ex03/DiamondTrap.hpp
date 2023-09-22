#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
    string  _name;
    
public:
    DiamondTrap(const string& name);
    DiamondTrap(const DiamondTrap& copy);
    ~DiamondTrap(void);

    // DiamondTrap& operator=(const DiamondTrap& other);
    friend std::ostream& operator<<(std::ostream& o, const DiamondTrap& rhs);

    void whoAmI();
};


#endif