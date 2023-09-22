#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
public:
    FragTrap(const string& name);
    FragTrap(const FragTrap& copy);
    ~FragTrap(void);

    void    highFiveGuys(void);

    FragTrap& operator=(const FragTrap& other);
    friend std::ostream& operator<<(std::ostream& o, const FragTrap& rhs);

private:
};
#endif