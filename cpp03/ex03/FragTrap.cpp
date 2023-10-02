#include "FragTrap.hpp"

void    FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << _name << " gives high five"<< std::endl;
}

FragTrap::FragTrap(void)
{
    _name = "default";
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
    :ClapTrap(name)
{
    std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
    : ClapTrap(copy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap Copy assginment constructor called" << std::endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}