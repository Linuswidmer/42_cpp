#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string& target)
{
    if (_energy_points <= 0)
        cout << "ScavTrap " << _name << " has no energy points left" << endl;
    else if (_hit_points <= 0)
        cout << "ScavTrap " << _name << " is dead" << endl;
    else
    {
        _energy_points--;
        cout << "ScavTrap " << _name << " attacks " << target <<
            ", causing " << _attack_damage << " points of damage" << endl; 
    }
}

void    ScavTrap::guardGate(void)
{
    cout << "ScavTrap is now in guard mode" << endl;
    _guard_status = true;
}

ScavTrap::ScavTrap(const string &name)
    :ClapTrap(name), _guard_status(false)
{
    cout << "ScavTrap " << _name << " Constructor called" << endl;
}

ScavTrap::~ScavTrap(void)
{
    cout << "ScavTrap " << _name << ": Destructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
    : ClapTrap(copy)
{
    cout << "ScavTrap Copy constructor called" << endl;
}

// test this...
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    cout << "ScavTrap Copy assginment constructor called" << endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const ScavTrap& rhs)
{
    o << static_cast<const ClapTrap&>(rhs);
    o << "guard_status: " << rhs._guard_status << endl;
    return (o);
}
