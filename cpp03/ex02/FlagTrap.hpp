#ifndef FLAGTRAP_H
# define FLAGTRAP_H
# include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
public:
    FlagTrap(const string& name);
    FlagTrap(const FlagTrap& copy);
    ~FlagTrap(void);

    void    highFiveGuys(void);

    FlagTrap& operator=(const FlagTrap& other);
    friend std::ostream& operator<<(std::ostream& o, const FlagTrap& rhs);

private:
    bool    _guard_status;
};
#endif