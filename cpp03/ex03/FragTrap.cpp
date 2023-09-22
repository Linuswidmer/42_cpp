#include "FragTrap.hpp"

void    FragTrap::highFiveGuys(void)
{
    cout << "FragTrap " << this->name() << " gives high five"<< endl;
}

FragTrap::FragTrap(const string &name)
    :ClapTrap(name)
{
    cout << "FragTrap " << this->name() << " Constructor called" << endl;
    this->hit_points(100);
    this->energy_points(100);
    this->attack_damage(30);
}

FragTrap::~FragTrap(void)
{
    cout << "FragTrap " << this->name() << ": Destructor called" << endl;
}

FragTrap::FragTrap(const FragTrap& copy)
    : ClapTrap(copy)
{
    cout << "FragTrap Copy constructor called" << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    cout << "FragTrap Copy assginment constructor called" << endl;
    if (this != &other) 
    {
        this->name(other.name());
        this->hit_points(other.hit_points());
        this->energy_points(other.energy_points());
        this->attack_damage(other.attack_damage());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const FragTrap& rhs)
{
    o << static_cast<const ClapTrap&>(rhs);
    return (o);
}
