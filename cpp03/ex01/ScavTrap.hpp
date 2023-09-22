#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(const string& name);
    ScavTrap(const ScavTrap& copy);
    ~ScavTrap(void);

    void attack(const std::string& target);
    void    guardGate(void);

    ScavTrap& operator=(const ScavTrap& other);
    friend std::ostream& operator<<(std::ostream& o, const ScavTrap& rhs);

private:
    bool    _guard_status;
};
#endif