#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
    std::string _name;

public:
    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& copy);
    virtual ~FragTrap(void);

    void    highFiveGuys(void);
    void    stats(void) const;

    FragTrap& operator=(const FragTrap& other);

private:
};
#endif