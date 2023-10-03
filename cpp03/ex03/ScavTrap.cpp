#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string& target)
{
    if (_energy_points <= 0)
        std::cout << "ScavTrap " << _name << " has no energy points left" << std::endl;
    else if (_hit_points <= 0)
        std::cout << "ScavTrap " << _name << " is dead" << std::endl;
    else
    {
        _energy_points = _energy_points -1;
        std::cout << "ScavTrap " << _name << " attacks " << target <<
            ", causing " << _attack_damage << " points of damage" << std::endl; 
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in guard mode" << std::endl;
    _guard_status = true;
}

ScavTrap::ScavTrap(void)
{
    this->_name = "default";
    std::cout << "ScavTrap " << _name << " Constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}


ScavTrap::ScavTrap(const std::string &name)
    :ClapTrap(name), _guard_status(false)
{
    std::cout << "ScavTrap " << _name << " Constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
    : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assginment constructor called" << std::endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
        _guard_status = other._guard_status;
    }
    return *this;
}

void    ScavTrap::stats(void) const
{
    std::cout << "ScavTrap stats called" << std::endl;
    std::cout << "hit points: " << _hit_points << std::endl
        << "energy points: " << _energy_points << std::endl
        << "attack_damage: " << _attack_damage << std::endl
        << "guard_status: " << _guard_status << std::endl;
}
