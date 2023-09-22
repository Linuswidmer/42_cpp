#include "FragTrap.hpp"

void    FragTrap::highFiveGuys(void)
{
    cout << "FragTrap " << _name << " gives high five"<< endl;
}

FragTrap::FragTrap(const string &name)
    :ClapTrap(name), _guard_status(false)
{
    cout << "FragTrap " << _name << " Constructor called" << endl;
}

FragTrap::~FragTrap(void)
{
    cout << "FragTrap " << _name << ": Destructor called" << endl;
}

FragTrap::FragTrap(const FragTrap& copy)
    : ClapTrap(copy)
{
    cout << "FragTrap Copy constructor called" << endl;
}

// test this...
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    cout << "FragTrap Copy assginment constructor called" << endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const FragTrap& rhs)
{
    o << static_cast<const ClapTrap&>(rhs);
    o << "guard_status: " << rhs._guard_status << endl;
    return (o);
}
