#include "FlagTrap.hpp"

void    FlagTrap::highFiveGuys(void)
{
    cout << "FlagTrap " << _name << " gives high five"<< endl;
}

FlagTrap::FlagTrap(const string &name)
    :ClapTrap(name), _guard_status(false)
{
    cout << "FlagTrap " << _name << " Constructor called" << endl;
}

FlagTrap::~FlagTrap(void)
{
    cout << "FlagTrap " << _name << ": Destructor called" << endl;
}

FlagTrap::FlagTrap(const FlagTrap& copy)
    : ClapTrap(copy)
{
    cout << "FlagTrap Copy constructor called" << endl;
}

// test this...
FlagTrap& FlagTrap::operator=(const FlagTrap& other)
{
    cout << "FlagTrap Copy assginment constructor called" << endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const FlagTrap& rhs)
{
    o << static_cast<const ClapTrap&>(rhs);
    o << "guard_status: " << rhs._guard_status << endl;
    return (o);
}
