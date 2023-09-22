#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string& target)
{
    if (this->energy_points() <= 0)
        cout << "ScavTrap " << this->name() << " has no energy points left" << endl;
    else if (this->hit_points() <= 0)
        cout << "ScavTrap " << this->name() << " is dead" << endl;
    else
    {
        this->energy_points(this->energy_points() - 1);
        cout << "ScavTrap " << this->name() << " attacks " << target <<
            ", causing " << this->attack_damage() << " points of damage" << endl; 
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
    cout << "ScavTrap " << this->name() << " Constructor called" << endl;
    this->hit_points(100);
    this->energy_points(50);
    this->attack_damage(20);
}

ScavTrap::~ScavTrap(void)
{
    cout << "ScavTrap " << this->name() << ": Destructor called" << endl;
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
        this->name(other.name());
        this->hit_points(other.hit_points());
        this->energy_points(other.energy_points());
        this->attack_damage(other.attack_damage());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const ScavTrap& rhs)
{
    o << static_cast<const ClapTrap&>(rhs);
    o << "guard_status: " << rhs._guard_status << endl;
    return (o);
}
