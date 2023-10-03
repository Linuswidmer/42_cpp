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
    :ClapTrap()
{
    _name = name;
    std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

void    FragTrap::stats(void) const
{
    std::cout << "FragTrap stats called" << std::endl;
    std::cout << "hit points: " << _hit_points << std::endl
        << "energy points: " << _energy_points << std::endl
        << "attack_damage: " << _attack_damage << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
    : ClapTrap(copy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    _name = copy._name;
    _hit_points = copy._hit_points;
    _energy_points =  copy._energy_points;
    _attack_damage = copy._attack_damage;
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